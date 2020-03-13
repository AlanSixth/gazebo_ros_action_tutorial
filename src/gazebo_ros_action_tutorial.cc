#include <functional>

#include <gazebo/common/Plugin.hh>
#include <gazebo/physics/physics.hh>
#include <gazebo_ros/node.hpp>

#include <rclcpp/rclcpp.hpp>
#include <rclcpp_action/rclcpp_action.hpp>

#include <example_interfaces/action/fibonacci.hpp>

namespace gazebo
{
  class MyPlugin : public ModelPlugin
  {
    public: void Load(physics::ModelPtr model, sdf::ElementPtr sdf)
    {
      std::cout << "Loading MyPlugin\n";

      this->model_ = model;
      this->ros_node_ = gazebo_ros::Node::Get(sdf);

      auto action_server = rclcpp_action::create_server<example_interfaces::action::Fibonacci>(
        ros_node_->get_node_base_interface(),
        ros_node_->get_node_clock_interface(),
        ros_node_->get_node_logging_interface(),
        ros_node_->get_node_waitables_interface(),
        "my_action",
        std::bind(&MyPlugin::handle_action_goal, this, std::placeholders::_1, std::placeholders::_2),
        std::bind(&MyPlugin::handle_action_cancel, this, std::placeholders::_1),
        std::bind(&MyPlugin::handle_action_accepted, this, std::placeholders::_1));

      this->update_connection_ = event::Events::ConnectWorldUpdateBegin(
          std::bind(&MyPlugin::OnUpdate, this));

      std::cout << "Loaded MyPlugin\n";
    }

    public: rclcpp_action::GoalResponse handle_action_goal(
      const rclcpp_action::GoalUUID&,
      example_interfaces::action::Fibonacci::Goal::ConstSharedPtr)
    {
      return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
    }

    public: rclcpp_action::CancelResponse handle_action_cancel(
      const std::shared_ptr<rclcpp_action::ServerGoalHandle<example_interfaces::action::Fibonacci>>)
    {
      return rclcpp_action::CancelResponse::ACCEPT;
    }

    public: void handle_action_accepted(
      const std::shared_ptr<rclcpp_action::ServerGoalHandle<example_interfaces::action::Fibonacci>>)
    {
      return;
    }

    public: void OnUpdate()
    {
      std::cout << "OnUpdate()\n";
    }

    private: physics::ModelPtr model_;
    private: gazebo_ros::Node::SharedPtr ros_node_;
    private: event::ConnectionPtr update_connection_;
  };

  // Register this plugin with the simulator
  GZ_REGISTER_MODEL_PLUGIN(MyPlugin)
}

