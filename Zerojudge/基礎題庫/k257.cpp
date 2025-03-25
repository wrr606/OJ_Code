//k257. 新生制服套量
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    string s;
    cin>>s;
    if(s.size()<4){
        int size=s.size();
        for(int i=0;i<4-size;i++){
            s.insert(1,"0");
        }
    }
    cout<<s<<endl;
}