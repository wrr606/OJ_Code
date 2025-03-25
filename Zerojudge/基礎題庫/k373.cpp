//k373. 0 and 1 加強版??@@@!!!
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    vector<pair<string,int> > x;
    string s;
    int a;
    while(cin>>s){
        bool b=1;
        cin>>a;
        for(auto &i:x){
            if(i.first==s){
                i.second=a;
                b=0;
                break;
            }
        }
        if(b)
            x.push_back({s,a});
    }
    for(auto i:x){
        if(i.second==0){
            cout<<i.first<<endl;
        }
    }
}