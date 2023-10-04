If = lambda c:lambda x:lambda y:c(x)(y)
x=10
If(x==10,print(123),print(0))