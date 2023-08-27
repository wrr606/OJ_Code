//Road_Reparation
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

struct node{
    int a,b,cost;
};

bool cmp(node a,node b){
    return a.cost<b.cost;
}

const int N=100005;
int n,num[N];
vector<node> cost;

int f(int cur){
    return cur==num[cur]?cur:num[cur]=f(num[cur]);
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        num[i]=i;
    int counter=n;
    ll ans=0;
    cost.assign(m,node());
    for(auto &i:cost)
        cin>>i.a>>i.b>>i.cost;
    sort(all(cost),cmp);
    for(const auto &i:cost){
        int a=f(i.a),b=f(i.b);
        if(a!=b){
            num[b]=a;
            counter--;
            ans+=i.cost;
        }
    }
    if(counter==1)
        cout<<ans;
    else
        cout<<"IMPOSSIBLE";
}