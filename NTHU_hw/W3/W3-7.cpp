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

constexpr int MAXN = 1e6 + 5;
vi que[MAXN];
int now_p[MAXN];

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n, m, cmd, a, b;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        que[i].emplace_back(i), now_p[i]=i;
    for(int i=0;i<m;i++){
        cin>>cmd>>a>>b;
        if(cmd){

        }
    }
    for(int i=1;i<=n;i++){
        cout<<"#"<<i<<": ";
        for(const auto &j:que[i]){
            if()
            cout<<j<<" ";
        }
        cout<<endl;
    }
}//not complete