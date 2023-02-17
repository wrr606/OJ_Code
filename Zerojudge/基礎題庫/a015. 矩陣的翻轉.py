while 1:
    try:
        in0=input().split()
        high=int(in0[0])
        width=int(in0[1])
        x=[]
        for i in range(high):
            x.insert(i,list(input()))
        for j in range(width):
            for i in range(high):
                print(x[i][0+2*j],end=" ")
            print("")
        #print(x)
        """
        7 8 9       7 4 1
        4 5 6       8 5 2
        1 2 3       9 6 3

        8 9
        5 6         8 5 2
        2 3         9 6 3
        """
    except:
        break