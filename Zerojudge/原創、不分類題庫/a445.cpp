//a445. 新手訓練系列- 我的朋友很少
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

vi friends;

int f(int cur){
    return cur==friends[cur]?cur:friends[cur]=f(friends[cur]);
}

void merge(int &a,int &b){
    a=f(a),b=f(b);
    if(a!=b){
        friends[b]=a;
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m,q;
    cin>>n>>m>>q;
    friends.assign(n+1,0);
    for(int i=1;i<=n;i++)
        friends[i]=i;
    while(m--){
        int a,b;
        cin>>a>>b;
        merge(a,b);
    }
    while(q--){
        int a,b;
        cin>>a>>b;
        a=f(a),b=f(b);
        if(a==b)
            cout<<":)\n";
        else
            cout<<":(\n";
    }
}