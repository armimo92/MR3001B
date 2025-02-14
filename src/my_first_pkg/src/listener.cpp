// Import the needed libraries to execute the ROS Node
#include "ros/ros.h"            // Allows the execution of the code in the ROS environment
#include <std_msgs/String.h>    // Allows using the ROS Message of type String
#include <std_msgs/Int32.h>     // Allows using the ROS Message of type Int32

// Including C++ nominal libraries
#include <iostream>             // Allows displaying data in the C++ environment
#include <string>               // Allows using string variables in the C++ environment

// Define the global variables of your code
int counter;
std::string text2listen;

// Define the callbacks for the ROS Subscribers here (if any)...
void textCallback(const std_msgs::String::ConstPtr& s)
{
    text2listen = s -> data;     // Asign the value allocated in the message container "data" to text2listen
}

void counterCallback(const std_msgs::Int32::ConstPtr& value)
{
    counter = value -> data;     // Asign the value allocated in the message container "data" to counter
}

// Design the main function of the code
int main(int argc, char **argv)
{
    // ROS commands that must be used by default
    ros::init(argc, argv, "listener");    // The word within quotations " " must match the name of your cpp file.
	ros::NodeHandle nh;                 // ROS Node initialization within code
	ros::Rate loop_rate(1);           // Running frequency of our code 

    // Create your ROS Publishers here (if any)...

    // Create your ROS Subscribers here (if any)...
    ros::Subscriber text_sub = nh.subscribe("text2show",1,&textCallback);
    ros::Subscriber counter_sub = nh.subscribe("counter",1,&counterCallback);

    // Declare your ROS Variables here (if any)...

    
    // Declare your local variables here (if any)...


    // ROS while loop set by default. Here you will code all your program 
    while(ros::ok())
    {
        // Displaying the information coming from the listened topics
        std::cout << text2listen << std::endl;
        std::cout << "This message has been received " << counter << " times." << std::endl;
        
        ros::spinOnce();
	loop_rate.sleep();
    }
    return 0;
}
