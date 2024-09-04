#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/Vector3.h>

#define PI 3.14

class smb_node{
    private:
        ros::Subscriber sub;
        ros::Publisher pub;
        ros::NodeHandle nh;
        int play=1;


    public:
        smb_node(){
            std::string param_name;
            std::string topic;
            int queue_size;

            ROS_INFO("Hello");

            if(nh.searchParam("topic",param_name)){
                nh.getParam(param_name,topic);
                ROS_INFO("Topic is %s",topic.c_str());
            }
            if(nh.searchParam("queue_size",param_name)){
                nh.getParam(param_name,queue_size);
                ROS_INFO("size is %d",queue_size);
            }


            sub = nh.subscribe(topic,queue_size,&smb_node::callback,this);
            pub = nh.advertise<geometry_msgs::Twist>("cmd_vel",100);

        }

        void callback(const sensor_msgs::LaserScan::ConstPtr &msg){
            if(play){
                float *p;
                float min = msg->range_max;
                int min_i;

                for(int i=0;i< msg->ranges.size(); i++){
                    if(min>msg->ranges[i]){
                        min= msg->ranges[i];
                        min_i=i;
                    }
                    // ROS_INFO("%d %f",i,msg->ranges[i]);
                }
                float ang_diff= (msg->angle_min + min_i*(msg->angle_increment))*180/PI;
                geometry_msgs::Twist speeds;

                // speeds->linear = {0,0,0};
                float k=0.05;
                
                if(ang_diff<3 && ang_diff>-3){
                    speeds.linear.x=2;    
                }
                else if(min<2){
                    speeds.linear.x=2;
                }
                else{
                    speeds.angular.z=k*ang_diff;
                }
                
                if(min<1){
                    speeds.angular.z=0;
                    speeds.linear.x=0;
                    play=0;
                    ROS_INFO("Collided with Pillar. Node Shutdown.");
                    pub.publish(speeds);
                    ros::shutdown();    
                    return;
                }
                

                pub.publish(speeds);
                ROS_INFO("Need to turn by %f",ang_diff);
                ROS_INFO("Min distance received: %f", min);
            }
        }

};


int main(int argc,char** argv){
    ros::init(argc,argv,"sub_node");
    smb_node myNode;

    ros::spin();
    return 0;
}
