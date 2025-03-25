//c356. Justin 愛加密
#include<stdio.h>
#include<string>

int main(){
    int n;
    char s[5001];
    scanf("%d ",&n);
    for(int i=0;i<n;i++){
        fgets(s,n+1,stdin);
        printf("%c",s[i]);
    }
}