//i524. 11988 - Broken Keyboard
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    string s;
    while(getline(cin,s)){
        list<char> key;
        auto iter=key.end();
        for(auto i:s){
            if(i=='[')
                iter=key.begin();
            else if(i==']')
                iter=key.end();
            else{
                key.insert(iter,i);
            }
        }
        for(auto i:key)
            cout<<i;
        cout<<endl;
    }
}