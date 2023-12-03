#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    map<int,int> polynomial;
    int n,x,y;
    cin>>n;
    while(n--){
        cin>>x>>y;
        polynomial[x]+=y;
    }
    cin>>n;
    while(n--){
        cin>>x>>y;
        polynomial[x]+=y;
    }
    bool b=0;
    for(auto inter=polynomial.rbegin();inter!=polynomial.rend();inter++){
        if((*inter).second){
            cout<<(*inter).first<<":"<<(*inter).second<<endl;
            b=1;
        }
    }
    if(!b)
        cout<<"NULL!\n";
}