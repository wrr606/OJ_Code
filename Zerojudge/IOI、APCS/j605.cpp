//j605. 1. 程式考試
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,a,b,max_time,max=-1,wrong=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        if(max<b){
            max_time=a;
            max=b;
        }
        if(b==-1)
            wrong++;
    }
    if(max-n-2*wrong<0)
        cout<<0<<" "<<max_time<<endl;
    else
        cout<<max-n-2*wrong<<" "<<max_time<<endl;
}