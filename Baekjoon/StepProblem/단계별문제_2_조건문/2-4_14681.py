while 1:
    x_position = int(input(""))
    if x_position >= -1000 and x_position<=1000 and x_position != 0:
        break
    else:
        print("")
while 1:
    y_position = int(input(""))
    if y_position >= -1000 and y_position<=1000 and y_position != 0:
        break
    else:
        print("")

if x_position > 0 and y_position > 0:
    print(1)
elif x_position < 0 and y_position > 0:
    print(2)
elif x_position < 0 and y_position < 0:
    print(3)
elif x_position > 0 and y_position < 0:
    print(4)
    
