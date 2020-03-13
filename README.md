# GAZEBO_ROS_ACTION_TUTORIAL

Creates a server inside a Gazebo plugin.

## How to run

1. `source /opt/ros/eloquent/setup.bash`
1. `cd <path_to_this_repo>` to the git repo
1. `colcon build`
1. `source install/setup.bash`
1. `export GAZEBO_PLUGIN_PATH=<path_to_this_repo>/install/gazebo_ros_action_tutorial/lib/`
1. `gazebo world/gazebo_ros_action_tutorial.world`

You will see the print out in the OnUpdate() call.
