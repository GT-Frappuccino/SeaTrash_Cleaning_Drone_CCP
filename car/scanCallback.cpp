
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
//void action(regions)



float minRegion(std::vector<float> ranges, int start_index, int end_index) {
    int initial_index = start_index;
    while (ranges[initial_index] < 0.35)
        initial_index++;

    float min = ranges[initial_index];

    //float degree = 0;
    for (int i = initial_index; i < end_index + 1; i++) {
        if (ranges[i] > 0.35 && ranges[i] < min) {
            min = ranges[i];
            //degree = RAD2DEG(scan->angle_min + scan->angle_increment * i);
        }
    }
    printf("%f   \n", min);
    return min;

}
