# my_4wheel_bot

This basic 4wheel_bot is to learn the major concpets in ROS like perception, tf, Navigation, localisation etc., and play on it.

use this below command to view the model of the robot 

```
roslaunch my_4wheel_bot view_model.launch
```

use this below command to generate the map using slam_gmapping and rqt_steering_robot, make sure to change the world_name arg in navigation.launch file if you want to add a new world in gazebo


```
roslaunch my_4wheel_bot slam.launch
```

use this command to save the generated map 

```
rosrun map_server map_saver -f path/to/save/the/map/mapname
```
replace the file_name in this line in the move_base.launch file after saved the map

```
<arg name="map_file" default="$(find my_4wheel_bot)/maps/file_name"/>
```

use these both two commands in a seperate terminal

```
roslaunch my_4wheel_bot navigation.launch
```
```
roslaunch my_4wheel_bot move_base.launch
```

TODO
----

* the laser scan also moves when the bot start moves to the goal given in the rviz.
* add some other cool stuffs over this base of the robot in the future, to make it more fun.

