
void action(map<string, float> region)
{
    float currentMin = region["back_br"];
    string direction_min = "back_br";
    for (auto it = region.cbegin(); it != region.cend(); ++it) {
        if (it->second < currentMin) {
            direction_min = it->first;
            currentMin = it->second;
        }
    }

    std::cout << "\t\t\t" << direction_min << "\t" << currentMin << std::endl;

    if (region["back1"] > FAR&& region["back_left"] > FAR&& region["left"] > FAR&& region["forward"] > FAR&& region["forward_right"] > FAR&& region["right"] > FAR&& region["back_right"] > FAR&& region["back2"] > FAR) {
        printf("nothing    \n");
        forward(10);
    }
    else if (direction_min == "forward_left" || direction_min == "left" || direction_min == "back_left" || direction_min == "back_bl") {

        printf("turn left \n");
        left(10);
    }
    else if (direction_min == "forward_right" || direction_min == "right" || direction_min == "back_right" || direction_min == "back_br") {

        printf("turn right   \n");
        right(10);
    }
    else if (direction_min == "forward") {

        printf("forward   \n");
        forward(10);
    }
}
