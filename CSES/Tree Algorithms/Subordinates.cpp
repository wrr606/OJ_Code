//Subordinates
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

const int N=200005;
vi routs[N];
int dp[N];

void DFS(int cur){
    for(const auto &i:routs[cur]){
        DFS(i);
        dp[cur]+=dp[i]+1;
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,temp;
    cin>>n;
    for(int i=2;i<=n;i++){
        cin>>temp;
        routs[temp].push_back(i);
    }
    cout<<n-1<<" ";
    DFS(1);
    for(int i=2;i<=n;i++){
        cout<<dp[i]<<" ";
    }
}