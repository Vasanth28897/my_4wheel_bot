# my_4wheel_bot

This basic 4wheel_bot is to learn the major concpets in ROS like perception, tf, Navigation, localisation etc., and play on it.

run this command to view the model of the robot 

```
roslaunch my_4wheel_bot view_model.launch
```

run this command to generate the map using slam_gmapping and rqt_steering_robot, make sure to change the world_name arg in navigation.launch file if you want to add a new world in gazebo


```
roslaunch my_4wheel_bot slam.launch
```

run this command to save the generated map 

```
rosrun map_server map_saver -f path/to/save/the/map/mapname
```
replace the file_name in this line in the move_base.launch file after saved the map

```
<arg name="map_file" default="$(find my_4wheel_bot)/maps/file_name"/>
```

run these both two commands seperate terminal

```
roslaunch my_4wheel_bot navigation.launch
```
```
roslaunch my_4wheel_bot move_base.launch
```

TODO
----

* the laser scan moves when the bot start moves to the given goal.
* maybe add some other cool stuffs over this basic robot.

