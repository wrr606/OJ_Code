#include<bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define all(x) x.begin(),x.end() 
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<ll> vll;
 
vi num,a,b;
set<ll> ans;
//1 2 3 4 7
 
ll sum(){
    ll x=0,y=0;
    for(const auto &i:a)
        x+=i;
    for(const auto &i:b)
        y+=i;
    return abs(x-y);
}
 
void recursion(int n){
    if(!n){
        ans.insert(sum());/*
        for(auto i:a)
            cout<<i<<" ";
        cout<<endl;
        cout<<"b:";
        for(auto i:b)
            cout<<i<<" ";
        cout<<endl<<endl;*/
        return;
    }
    a.push_back(num[n-1]);
    recursion(n-1);
    a.pop_back();
    b.push_back(num[n-1]);
    recursion(n-1);
    b.pop_back();
}
 
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    num.assign(n,0);
    for(auto &i:num)
        cin>>i;
    recursion(n);
    cout<<*(ans.begin());
}