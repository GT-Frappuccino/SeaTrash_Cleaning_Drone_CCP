#include "sensor_msgs/LaserScan.h"
#include <map>
using std::map;
using std::string;


void scanCallback(const sensor_msgs::LaserScan::ConstPtr& scan)
{
    map<string, float> region;

    region.insert(map<string, float> ::value_type("back1", minRegion((scan->ranges), 0, 30)));//belowdown
    region.insert(map<string, float> ::value_type("backleft", minRegion(scan->ranges),31, 93)));
    region.insert(map<string, float> ::value_type("left", minRegion(scan->ranges),94,155)));
    region.insert(map<string, float> ::value_type("forwardleft", minRegion(scan->ranges) ,156,218)));
    region.insert(map<string, float> ::value_type("forward", minRegion(scan->ranges), 219, 281));
    region.insert(map<string, float> ::value_type("forwardright", minRegion(scan->ranges), 282,344));
    region.insert(map<string, float> ::value_type("right", minRegion(scan->ranges), 345, 407));
    region.insert(map<string, float> ::value_type("backright", minRegion(scan->ranges), 408 ,470);
    region.insert(map<string, float> ::value_type("back2", minRegion(scan->ranges), 471, 498));
}





