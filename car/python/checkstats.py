def checkState():
    global state, BIG_GPS_DISTANCE_ERROR , SMALL_GPS_DISTANCE_ERROR
    if len(gps_list) > 0:  # there is gps position to go
        if not isBoatCenter(BIG_GPS_DISTANCE_ERROR):
            state = 2
        else:
            if not isTrashFinish() :
                state = 3
            elif not isBoatCenter(SMALL_GPS_DISTANCE_ERROR):
                state = 4  # go to center
            else:
                del gps_list[0]
    else:
        state = 1  # stay
