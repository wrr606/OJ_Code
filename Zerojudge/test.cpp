#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

int main(){
    string s;
    while(cin>>s){
        map<char,int> x;
        for(auto i:s){
            x[i]++;
        }
        for(auto i:x){
            cout<<i.first<<"\t"<<i.second<<endl;
        }
    }
}