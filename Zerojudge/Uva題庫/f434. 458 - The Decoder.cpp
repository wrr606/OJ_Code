#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    string s;
    while(cin>>s){
        for(auto i:s){
            cout<<char(int(i)-7);
        }
        cout<<endl;
    }
}