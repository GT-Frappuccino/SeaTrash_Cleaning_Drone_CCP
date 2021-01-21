
def minRegion(ranges):
    
    min = ranges[0]
    initial_index = 0
    
    while (ranges[initial_index] < 0.35):
        initial_index = initial_index + 1
        if (initial_index >= len(ranges) - 1):
            min = 0.0 
            break
        else:
            min = ranges[initial_index]
        
    for i in range(initial_index, len(ranges)):
        if (ranges[i] > 0.35 and ranges[i] < min and not math.isinf(ranges[i])):
            min = ranges[i]
    
    if (math.isinf(min)):
        min = 0.0
    return min
