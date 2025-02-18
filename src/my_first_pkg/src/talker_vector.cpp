// Import the needed libraries to execute the ROS Node
#include "ros/ros.h"            // Allows the execution of the code in the ROS environment
#include <geometry_msgs/Vector3.h>     // Allows using the ROS Message of type Int32
#include <geometry_msgs/Twist.h>  

// Import the C++ nominal libraries
#include <iostream>             // Allows displaying data in the C++ environment

// Import the Eigen3 library
#include <eigen3/Eigen/Dense>


// Define the global variables of your code
Eigen::Vector3f data_vector_1(0,0,0);
Eigen::Vector3f data_vector_2(0,0,0);
Eigen::Vector3f data_vector_3(0,0,0);

float x = 0;

// Define the callbacks for the ROS Subscribers here (if any)...

// Design the main function of the code
int main(int argc, char **argv)
{
    // ROS commands that must be used by default
    ros::init(argc, argv, "talker_vector");    // The word within quotations " " must match the name of your cpp file.
    ros::NodeHandle nh;                 // ROS Node initialization within code
    ros::Rate loop_rate(10);            // Running frequency of our code 

    // Create your ROS Publishers here (if any)...
    ros::Publisher vec_data_1_pub = nh.advertise<geometry_msgs::Vector3>("vector_3",100);
    ros::Publisher vec_data_2_pub = nh.advertise<geometry_msgs::Twist>("vector_6",100);

    // Create your ROS Subscribers here (if any)...


    // Declare your ROS Variables here (if any)...
    geometry_msgs::Vector3 vector_var;
    geometry_msgs::Twist twist_var;
    
    // Declare your local variables here (if any)...


    // ROS while loop set by default. Here you will code all your program 
    while(ros::ok())
    {
        data_vector_1(0) = 0.2*x;
        data_vector_1(1) = 0.5*x;
        data_vector_1(2) = 0.1*x;

        data_vector_2(0) = x/2;
        data_vector_2(1) = std::pow(x,0.5);
        data_vector_2(2) = 0.01*x;


        data_vector_3(0) = x*0.02;
        data_vector_3(1) = x*0.05;
        data_vector_3(2) = x;

        x = x + 0.1;
        
        
        // Define the data (local variables) to send through ROS Topics  
        vector_var.x = data_vector_1(0);
        vector_var.y = data_vector_1(1);
        vector_var.z = data_vector_1(2);
        
        twist_var.linear.x = data_vector_2(0);
        twist_var.linear.y = data_vector_2(1);
        twist_var.linear.z = data_vector_2(2);

        twist_var.angular.x = data_vector_3(0);
        twist_var.angular.y = data_vector_3(1);
        twist_var.angular.z = data_vector_3(2);

        // Publish the messages
        vec_data_1_pub.publish(vector_var);
        vec_data_2_pub.publish(twist_var);

        
        ros::spinOnce();
	loop_rate.sleep();
    }
    return 0;
}
