//d587. 參貳壹真好吃
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,temp;
    cin>>n;
    multiset<int> list;
    while(n--){
        cin>>temp;
        list.insert(temp);
    }
    for(auto i:list)
        cout<<i<<" ";
}