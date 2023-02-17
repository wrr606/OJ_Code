while True:
    try:
        a, b, c = map(int, input().split(' '))
        rd = a*(10**c)//b 
        rs = str(rd)
        if len(rs) < c: 
            for i in range(c - len(rs)):
                rs = '0' + rs
        m = rs[(c*-1):] 
        n = rs[:(c*-1)] 
        if n == '': n = '0'
        print(f'{n}.{m}')   
    except:
        break