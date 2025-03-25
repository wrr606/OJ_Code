//j606. 2. 造字程式
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int k,q,r,temp;
    string s,t;
    cin>>k>>q>>r;
    vector<string> x;
    cin>>s;
    t="";
    for(int j=0;j<k;j++){
        t+='1';
    }
    for(int i=0;i<q;i++){
        for(int j=0;j<k;j++){
            cin>>temp;
            t[temp-1]=s[j];
        }
        x.push_back(t);
        s=t;
        //cout<<t<<endl;
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<q;j++){
            cout<<x[j][i];
        }
        cout<<endl;
    }
}