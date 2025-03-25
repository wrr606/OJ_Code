//c381. 聖經密碼
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m;
    while(cin>>n>>m){
        if(!n&&!m)
            break;
        string temp,s;
        while(n--){
            cin>>temp;
            s+=temp;
        }
        while(m--){
            cin>>n;
            cout<<s[n-1];
        }
        cout<<endl;
    }
}