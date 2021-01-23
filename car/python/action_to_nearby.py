
def action(region):
    
    currentMin = min(region.values())
    direction_min = min(region.keys(),key=(lambda k: region[k]))

    if (region["back_bl"] > FAR and region["back_left"] > FAR and region["left"] > FAR and region["forward"] > FAR and region["forward_right"] > FAR and           region["right"] > FAR and region["back_right"] > FAR and  region["back_br"] > FAR):
        print("nothing    \n")
        forward(0.01)
    
    elif (direction_min == "forward_left" or direction_min == "left" or direction_min == "back_left" or direction_min == "back_bl"): 
        print("turn left \n")
        left(0.01)
    
    elif (direction_min == "forward_right" or direction_min == "right" or direction_min == "back_right" or direction_min == "back_br"):
        print("turn right   \n")
        right(0.01)
    
    elif (direction_min == "forward"):
        print("forward   \n")
        forward(0.01)
