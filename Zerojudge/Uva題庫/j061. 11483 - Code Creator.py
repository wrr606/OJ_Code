#j061. 11483 - Code Creator
cnt=1
while 1:
        n=int(input())
        if n==0:
            break
        txt=[]
        for i in range(n):
            txt.append(input())
        print(f"Case {cnt}:")
        print("#include<string.h>")
        print("#include<stdio.h>")
        print("int main()\n{")
        for i in txt:
            print("printf(\"",end="")
            i=i.replace('\\','\\\\').replace('\"','\\\"').replace('\'','\\\'')
            print(i,end="")
            print("\\n\");")
        print("printf(\"\\n\");")
        print("return 0;\n}")
        cnt+=1