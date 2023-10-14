#include <ros/ros.h>
#include <sensor_msgs/Image.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/opencv.hpp>

class SensorChecking {
public:
    SensorChecking() {
        std::string sub_topic_name = "/camera/rgb/image_raw";
        image_transport::ImageTransport it(nh);
        camera_subscriber = it.subscribe(sub_topic_name, 1, &SensorChecking::cameraCallback, this);
        out.open("/home/luqman/output.avi", cv::VideoWriter::fourcc('M','J','P','G'), 10, cv::Size(640, 480));
    }

    void cameraCallback(const sensor_msgs::ImageConstPtr& data) {
        cv_bridge::CvImagePtr cv_ptr;
        try {
            cv_ptr = cv_bridge::toCvCopy(data, sensor_msgs::image_encodings::BGR8);
        } catch (cv_bridge::Exception& e) {
            ROS_ERROR("cv_bridge exception: %s", e.what());
            return;
        }
        
        cv::Mat frame = cv_ptr->image;
        cv::imshow("output", frame);
        cv::waitKey(1);
        
        out.write(frame);

        // Rest of your code...
    }

private:
    ros::NodeHandle nh;
    image_transport::Subscriber camera_subscriber;
    cv::VideoWriter out;
};

int main(int argc, char** argv) {
    std::string node_name = "camera_check";
    ros::init(argc, argv, node_name);
    
    SensorChecking sensor;
    
    ros::spin();

    return 0;
}

