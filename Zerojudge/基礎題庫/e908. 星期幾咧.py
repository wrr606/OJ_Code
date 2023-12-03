daydict={"Sunday":7,"Monday":1,"Tuesday":2,"Wednesday":3,"Thursday":4,"Friday":5,"Saturday":6}
daydict1={0:"Sunday",1:"Monday",2:"Tuesday",3:"Wednesday",4:"Thursday",5:"Friday",6:"Saturday"}
n=input()
x=int(input())
day=(x+daydict[n])%7
print(daydict1[day])