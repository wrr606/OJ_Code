//k950. easy math
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long int

//快速冪
int qpow(int a,int b){
    int res=1;
    while(b){
        if(b&1)
            res*=a;
        b>>=1;
        a*=a;
    }
    return res;
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    vector<int> num;
    while(cin>>n)
        num.push_back(n);
    int ans=num.back();
    num.pop_back();
    int a=0,s=num[0]*2,m=1,d=num[0]*num[0],poww=num.back();
    for(const auto &i:num)
        a+=i;
    if(a==ans)
        cout<<"+\n";
    for(const auto &i:num)
        s-=i;
    if(s==ans)
        cout<<"-\n";
    for(const auto &i:num)
        m*=i;
    if(m==ans)
        cout<<"*\n";
    for(const auto &i:num)
        d/=i;
    if(d==ans)
        cout<<"/\n";
    for(int i=num.size()-2;i>=0;i--)//1 2 3 6  
        poww=qpow(num[i],poww);
    if(poww==ans)
        cout<<"**\n";
}