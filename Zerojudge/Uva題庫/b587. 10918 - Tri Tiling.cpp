//b587. 10918 - Tri Tiling
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define all(x) x.begin(),x.end() 
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vector<int> > vvi;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

int f[31]={1};

int F(int n){
    if(f[n])
        return f[n];
    int temp=0;
    for(int i=4;i<=n;i+=2)
        temp+=F(n-i);
    f[n]=3*F(n-2)+(temp<<1);
    return f[n];
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    while(cin>>n&&n!=-1){
        if(n&1)
            cout<<0;
        else
            cout<<F(n);
        cout<<endl;
    }
}