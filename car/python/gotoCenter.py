def gotoCenter(region): # avoid obstacles
    global SAFE_DISTANCE, lat, lng
    go_list = [min(SAFE_DISTANCE, region['forward']), min(SAFE_DISTANCE, region['forward_left']),min(SAFE_DISTANCE, region['forward_right'])]
    pre_error_to_center = math.sqrt((gps_list[0][0] - pre_lat) ** 2 + (gps_list[0][1] - pre_lng) ** 2)
    error_to_center = math.sqrt((gps_list[0][0] - lat) ** 2 + (gps_list[0][1] - lng) ** 2)
    if go_list[0] == SAFE_DISTANCE and go_list[1] == SAFE_DISTANCE and go_list[2] == SAFE_DISTANCE :
        if pre_error_to_center < error_to_center :
            left(0.01)
        else :
            forward(0.01)
    else :
        if go_list[1] < go_list[2] :
            right(0.01)
        else :
            left(0.01)
