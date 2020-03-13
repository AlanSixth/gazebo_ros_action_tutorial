# GAZEBO_ROS_ACTION_TUTORIAL

which simply doesn't work...

## How to replicate

1. `source /opt/ros/eloquent/setup.bash`
1. `cd <path_to_this_repo>` to the git repo
1. `colcon build`
1. `source install/setup.bash`
1. `export GAZEBO_PLUGIN_PATH=<path_to_this_repo>/install/gazebo_ros_action_tutorial/lib/`
1. `gazebo world/gazebo_ros_action_tutorial.world`

And you don't see the prints in the plugin. If you comment out the lines that create the action server, then you do see the prints.
