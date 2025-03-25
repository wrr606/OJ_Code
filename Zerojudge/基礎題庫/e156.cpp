//e156. 良心題: 求和
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

ll add(ll n){
    if(n==1)
        return 1;
    return n+add(n-1);
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    cout<<add(n);
}