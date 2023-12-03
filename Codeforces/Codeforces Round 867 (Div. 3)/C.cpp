#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        ll temp;
        cin>>temp;
        if(temp==4){
            cout<<26<<endl;
            continue;
        }
        cout<<26+(temp-4)+(5+temp)*(temp-4)<<endl;
    }
}