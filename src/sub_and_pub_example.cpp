//
// Created by charris on 6/29/20.
//

#include "ros/ros.h"
#include "std_msgs/String.h"
#include "ros_tutorials/Score.h"


class RosNodeExample{
public:
    explicit RosNodeExample(ros::NodeHandle &nh): _nh(nh){
        initialize_stuff();
    }

    void initialize_stuff() {
        ROS_INFO("Initializing subs and pubs...");
        _pub = _nh.advertise<ros_tutorials::Score>("score_updated", 10);

        // Subscriber
        _sub = _nh.subscribe("score", 10, &RosNodeExample::callback, this);

        // Params
        _name = "Johnathan";
        _number = 100;

    }

    void callback(const ros_tutorials::Score::ConstPtr &msg) {
        ROS_INFO("Message received for %s with score %i", msg->first_name.c_str(), msg->score);

        ros_tutorials::Score score_new;
        score_new.score = msg->score + 1;
        score_new.first_name = _name;
        score_new.last_name = msg->last_name;
        score_new.age = msg->age;

        _pub.publish(score_new);
    }

    // OTHER FUNCTIONS HERE

    void spin()
    {
        ros::spin();
    }

private:

    // Node
//    ros::NodeHandle _nh;
    ros::NodeHandle _nh;

    ros::Subscriber _sub;

    // Publishers
    ros::Publisher _pub;

    uint _number;
    std::string _name;
};



int main(int argc, char **argv)
{
    // Initialize ROS
    ros::init(argc,argv,"pub_sub_node");
    ros::NodeHandle nh;

    RosNodeExample pf(nh);
    ROS_INFO("node spinning.");
    pf.spin();

    return 0;
}

//
// Created by charris on 6/29/20.
//

