#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

set<int> x,y;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t,n,temp;
    cin>>t;
    while(t--){
        cin>>n;
        x.clear(),y.clear();
        cin>>temp;
        x.insert(temp);
        for(int i=1;i<n;i++){
            cin>>temp;
            y.insert(*(x.rbegin())-temp);
            x.insert(temp);
        }
        cout<<*(y.rbegin())<<endl;
    }
}