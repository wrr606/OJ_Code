//10714 Ants
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
        int length,n,maxtime=-1,mintime=-1,ant;
        cin>>length>>n;
        for(int i=0;i<n;i++){
            cin>>ant;
            maxtime=max(max(abs(length-ant),ant),maxtime);
            mintime=max(min(abs(length-ant),ant),mintime);
        }
        cout<<mintime<<" "<<maxtime<<endl;
    }
}