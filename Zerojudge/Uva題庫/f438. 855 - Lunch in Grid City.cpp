#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t,s,a,f;
    cin>>t;
    while(t--){
        cin>>s>>a>>f;
        vector<int> x(f),y(f);
        for(int i=0;i<f;i++){
            cin>>x[i]>>y[i];
        }
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        if(f%2==0)
            cout<<"(Street: "<<x[f/2-1]<<", Avenue: "<<y[f/2-1]<<")\n";
        else
            cout<<"(Street: "<<x[f/2]<<", Avenue: "<<y[f/2]<<")\n";
    }
}