
def isBoatCenter(gps_distance_error): # true if car gps == received gps
        if math.sqrt((gps_list[0][0]-lat)**2+(gps_list[0][1]-lng)**2) < gps_distance_error:
            return True
        else:
     
            return False
def isTrashFinish(region):
    global NO_TRASH_IN_BOUNDARY
    currentMin = min(region.values())
    if currentMin < NO_TRASH_IN_BOUNDARY :
        return False
    else :
        return True


