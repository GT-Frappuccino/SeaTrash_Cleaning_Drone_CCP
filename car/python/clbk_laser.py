def clbk_laser(msg):
    # 720 / 5 = 144
    global state
    regions = {
        'back_br': minRegion(msg.ranges[0:31]),
        'back_right': minRegion(msg.ranges[31:94]),
        'right': minRegion(msg.ranges[94:156]),
        'forward_right': minRegion(msg.ranges[156:219]),
        'forward': minRegion(msg.ranges[219:282]),
        'forward_left': minRegion(msg.ranges[282:345]),
        'left': minRegion(msg.ranges[345:408]),
        'back_left': minRegion(msg.ranges[408:471]),
        'back_bl': minRegion(msg.ranges[471:499])
    }
    print(regions['forward'])
    UpdateMyGps()
    checkState()
    if (state == 0):
        print("Controller")
    elif (state == 1):
        stay()
    elif (state == 2 or state == 4):
        gotoCenter(regions)
    elif (state == 3):
        action(regions)

