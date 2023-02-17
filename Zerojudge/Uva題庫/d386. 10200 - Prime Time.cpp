#include <bits/stdc++.h>
using namespace std;

int prime(int n){
    for (int i = 2; i * i <= n; i++) if ((n % i) == 0) return 0;
    return 1;
}

int dp[10006]={};

int main(){
    for (int i = 0; i <= 10005; i++) dp[i] = prime(i * i + i + 41);
    ios::sync_with_stdio(0),cin.tie(0);
    int a,b;
    while(cin>>a>>b){
        double counter_1=0,counter=b-a+1;
        for(int i=a;i<=b;i++){
            counter_1+=dp[i];
        }
        //cout<<"counter_1:"<<counter_1<<endl;
        printf("%.2lf\n",counter_1/counter*100+0.0000000001);
    }
}