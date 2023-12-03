#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    //BRKRBQNN
    string s;
    int b[2]={},q=1,w=1,k=0;
    bool x=0,y=0;
    cin>>s;
    for(int i=0;i<8;i++){
        if(s[i]=='R'&&w){
            w=0;
        }
        if(s[i]=='K'&&!w){
            k=1;
        }
        if(s[i]=='R'&&!w&&k){
            x=1;
        }
        if(s[i]=='B'&&q){
            b[0]=i;
            q=0;
        }
        if(s[i]=='B'&&!q){
            b[1]=i;
        }
    }
    if(b[0]%2!=b[1]%2){
        y=1;
    }
    if(x&&y){
        cout<<"Yes\n";
    }
    else{
        cout<<"No\n";
    }
}