//l184. 求和問題 2
#include<stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        long long int a,b,c;
        scanf("%lld%lld%lld",&a,&b,&c);
        printf("%lld\n",a+b+c);
    }
}