//d909. 公路局長好煩惱！？
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

const int N=10005;

struct node{
    int a,b,cost;
};

bool cmp(node a,node b){
    return a.cost<b.cost;
}

vector<node> cost;
int num[N];

int f(int cur){
    return cur==num[cur]?cur:num[cur]=f(num[cur]);
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m;
    cin>>n>>m;
    ll ans=0;
    for(int i=0;i<n;i++)
        num[i]=i;
    cost.assign(m,node());
    for(auto &i:cost)
        cin>>i.a>>i.b>>i.cost;
    sort(all(cost),cmp);
    for(const auto &i:cost){
        int a=f(i.a),b=f(i.b);
        if(a!=b){
            num[b]=a;
            ans+=i.cost;
        }
    }
    cout<<ans;
}