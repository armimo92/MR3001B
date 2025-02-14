// Import the needed libraries to execute the ROS Node
#include "ros/ros.h"            // Allows the execution of the code in the ROS environment
#include <std_msgs/String.h>    // Allows using the ROS Message of type String
#include <std_msgs/Int32.h>     // Allows using the ROS Message of type Int32

// Including C++ nominal libraries
#include <iostream>             // Allows displaying data in the C++ environment
#include <string>               // Allows using string variables in the C++ environment

// Define the global variables of your code
int counter = 0;
std::string text2show;

// Define the callbacks for the ROS Subscribers here (if any)...

// Design the main function of the code
int main(int argc, char **argv)
{
    // ROS commands that must be used by default
    ros::init(argc, argv, "talker");    // The word within quotations " " must match the name of your cpp file.
	ros::NodeHandle nh;                 // ROS Node initialization within code
	ros::Rate loop_rate(1);           // Running frequency of our code 

    // Create your ROS Publishers here (if any)...
    ros::Publisher text_pub = nh.advertise<std_msgs::String>("text2show",1);
    ros::Publisher counter_pub = nh.advertise<std_msgs::Int32>("counter",10);

    // Create your ROS Subscribers here (if any)...


    // Declare your ROS Variables here (if any)...
    std_msgs::String text_var;
    std_msgs::Int32 count_var;
    
    // Declare your local variables here (if any)...


    // ROS while loop set by default. Here you will code all your program 
    while(ros::ok())
    {
        text2show = "Welcome to your ROS Course!!";
        counter = counter + 1;

        // Define the data (local variables) to send through ROS Topics  
        text_var.data = text2show;
        count_var.data = counter;

        // Publish the messages
        text_pub.publish(text_var);
        counter_pub.publish(count_var);

        
        ros::spinOnce();
		loop_rate.sleep();
    }
    return 0;
}