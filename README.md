# my_4wheel_bot

This basic 4wheel_bot is to learn the major concpets in ROS like perception, tf, Navigation, localisation etc., and play on it.

##run this command to view the model of the robot 

```
roslaunch my_4wheel_bot view_model.launch
```

##run this command to generate the map using slam_gmapping and rqt_steering_robot, make sure to change the world_name arg in navigation.launch file if you want to add a new world in gazebo
NOTE: the angular velocity lag when the bot rotates to generate the map. Don't know why.

```
roslaunch my_4wheel_bot slam.launch
```

##run this command to save the generated map 

```
rosrun map_server map_saver -f path/to/save/the/map/mapname
```

##run this both two commands seperate terminal

```
roslaunch my_4wheel_bot navigation.launch
```
```
roslaunch my_4wheel_bot move_base.launch
```

there is an error or i don't know what's happening when you give 2d_Nav_goal in rviz the bot does not move...but you can see "Got New Plan" in rviz.

the roswtf command gives like this
```
Loaded plugin tf.tfwtf
No package or stack in the current directory
================================================================================
Static checks summary:

No errors or warnings
================================================================================
Beginning tests of your ROS graph. These may take a while...
analyzing graph...
... done analyzing graph
running graph rules...
... done running graph rules
running tf checks, this will take a second...
... tf checks complete

Online checks summary:

Found 2 warning(s).
Warnings are things that may be just fine, but are sometimes at fault

WARNING The following node subscriptions are unconnected:
 * /rviz:
   * /map_updates
 * /gazebo:
   * /gazebo/set_link_state
   * /gazebo/set_model_state
   * /diff_drive_controller/cmd_vel
 * /move_base:
   * /odom
   * /move_base/cancel

WARNING These nodes have died:
 * spawning_lidar-8


Found 1 error(s).

ERROR The following nodes should be connected but aren't:
 * /move_base->/move_base (/move_base/local_costmap/footprint)
 * /move_base->/move_base (/move_base/global_costmap/footprint)

```
