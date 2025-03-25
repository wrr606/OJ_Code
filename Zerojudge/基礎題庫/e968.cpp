//e968. 2. 班級名單 (Student list)
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,a,b,c;
    cin>>n>>a>>b>>c;
    bitset<21> member;
    member[a]=1,member[b]=1,member[c]=1;
    for(int i=n;i>=1;i--){
        if(!member[i]){
            cout<<"No. "<<i<<endl;
        }
    }
}