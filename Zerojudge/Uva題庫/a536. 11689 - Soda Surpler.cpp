#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,e,f,c;
    cin>>n;
    while(n--){
        int counter=0;
        cin>>e>>f>>c;
        e+=f;
        while(e/c!=0){
            counter+=e/c;
            e=e/c+e%c;
        }
        cout<<counter<<endl;
    }
}