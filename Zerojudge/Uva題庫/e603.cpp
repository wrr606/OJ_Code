//e603. 10104 - Euclid Problem
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

//擴展歐幾里得
int exgcd(int a,int b,int &x,int &y){
    if(b==0){
        x=1,y=0;
        return a;
    }
    int gcd=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return gcd;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int a,b,x,y,ans;
    while(cin>>a){
        cin>>b;
        ans=exgcd(a,b,x,y);
        cout<<x<<" "<<y<<" "<<ans<<endl;
    }
}