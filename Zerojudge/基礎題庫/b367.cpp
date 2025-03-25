#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

vector<int> x(200);

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t,n,m;
    cin>>t;
    while(t--){
        bool b=1;
        cin>>n>>m;
        for(int i=1;i<=n*m;i++){
            cin>>x[i];
        }
        for(int i=n*m;i>n*m/2;i--){
            if(x[i]!=x[n*m-i+1]){
                b=0;
                break;
            }
        }
        if(b)
            cout<<"go forward\n";
        else
            cout<<"keep defending\n";
    }
}