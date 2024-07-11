#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>

void callback(const sensor_msgs::LaserScan::ConstPtr &msg){
    float *p;
    float min = msg->range_max;

    for(int i=0;i< msg->ranges.size(); i++){
        if(min>msg->ranges[i]){
            min= msg->ranges[i];
            
        }
        // ROS_INFO("%d %f",i,msg->ranges[i]);
    }
    ROS_INFO("Min distance received: %f", min);
}

int main(int argc,char** argv){
    ros::init(argc,argv,"sub_node");
    ros::NodeHandle nh;

    std::string param_name;
    std::string topic;
    int queue_size;

    ROS_INFO("HELlo");

    if(nh.searchParam("topic",param_name)){
        nh.getParam(param_name,topic);
        ROS_INFO("Topic is %s",topic.c_str());
    }
    if(nh.searchParam("queue_size",param_name)){
        nh.getParam(param_name,queue_size);
        ROS_INFO("size is %d",queue_size);
    }

    ros::Subscriber sub=nh.subscribe(topic,queue_size,callback);

    ros::spin();
    return 0;
}
