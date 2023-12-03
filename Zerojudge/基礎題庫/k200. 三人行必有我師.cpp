//k200. 三人行必有我師
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int a,b,c;
    cin>>a>>b>>c;
    cout<<max(max(a,b),c);
}