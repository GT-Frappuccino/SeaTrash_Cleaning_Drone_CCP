
float minRegion(std::vector<float> ranges, int start_index, int end_index) {
    int initial_index = start_index;
    float min = ranges[initial_index];
    while (ranges[initial_index] < 0.35) {
        if (initial_index >= end_index) {
            min = 0.0; break;
        }

        else
            float min = ranges[initial_index];
        initial_index++;
    }

    for (int i = initial_index; i < end_index + 1; i++) {
        if (ranges[i] > 0.35 && ranges[i] < min && !std::isinf(ranges[i])) {
            min = ranges[i];
         
        }
    }

    if (std::isinf(min))
        min = 0.0;
    return min;

}
