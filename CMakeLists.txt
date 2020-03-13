cmake_minimum_required(VERSION 3.5)
project(gazebo_ros_action_tutorial)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")
endif()

find_package(ament_cmake REQUIRED)
find_package(example_interfaces REQUIRED)
find_package(gazebo_dev REQUIRED)
find_package(gazebo_ros REQUIRED)
find_package(rclcpp REQUIRED)
# find_package(rosidl_default_generators REQUIRED)

include_directories(include)

add_library(gazebo_ros_action_tutorial SHARED src/gazebo_ros_action_tutorial.cc)
ament_target_dependencies(gazebo_ros_action_tutorial
  gazebo_dev
  gazebo_ros
  rclcpp
)
ament_export_libraries(gazebo_ros_action_tutorial)

install(TARGETS
  gazebo_ros_action_tutorial
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin)

ament_package()
