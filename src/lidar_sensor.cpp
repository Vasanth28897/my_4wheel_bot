#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>

class SensorChecking {
public:
    SensorChecking() {
        std::string sub_topic_name = "/scan";
        lidar_subscriber = nh.subscribe(sub_topic_name, 1, &SensorChecking::lidarCallback, this);
    }

    void lidarCallback(const sensor_msgs::LaserScan::ConstPtr& data) {
        float region_a = std::min_element(data->ranges.begin(), data->ranges.begin() + 120);
        region_a = std::min(region_a, 10.0f);
        float region_b = std::min_element(data->ranges.begin() + 121, data->ranges.begin() + 240);
        float region_c = std::min_element(data->ranges.begin() + 241, data->ranges.begin() + 360);
        ROS_INFO("A: %.3f B: %.3f C: %.3f", region_a, region_b, region_c);
        
        // Rest of your code...

    }

private:
    ros::NodeHandle nh;
    ros::Subscriber lidar_subscriber;
};

int main(int argc, char** argv) {
    std::string node_name = "lidar_check";
    ros::init(argc, argv, node_name);
    
    SensorChecking sensor;
    
    ros::spin();

    return 0;
}
