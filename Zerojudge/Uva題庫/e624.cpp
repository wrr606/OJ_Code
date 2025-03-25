//e624. 10340 - All in All
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    string s,t;
    int point;
    bool ans=true,n=false;
    while(cin>>s>>t){
        point=0;
        for(auto i:s){
            n=false;
            for(point;point<t.size();point++){
                if(i==t[point]){
                    n=true;
                    break;
                }
            }
            if(!n){
                ans=false;
            }
            else{
                ans=true;
            }
        }
        if(ans){
            cout<<"Yes\n";
        }
        else{
            cout<<"No\n";
        }
    }
}