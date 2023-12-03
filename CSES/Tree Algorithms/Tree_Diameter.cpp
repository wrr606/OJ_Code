//Tree_Diameter
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
int mx=-1,r=-1;
 
void DFS(int cur,int last,int dis=0){
    if(dis>mx)
        mx=dis,r=cur;
    for(const auto &i:routs[cur]){
        if(i==last)
            continue;
        DFS(i,cur,dis+1);
    }
}
 
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        routs[a].push_back(b);
        routs[b].push_back(a);
    }
    DFS(1,1);
    int temp=r;
    mx=-1,r=-1;
    DFS(temp,temp);
    cout<<mx;
}