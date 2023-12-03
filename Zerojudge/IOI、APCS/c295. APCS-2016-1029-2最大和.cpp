//c295. APCS-2016-1029-2最大和
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

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m,x,ans=0;
    cin>>n>>m;
    priority_queue<int> num[n];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>x;
            num[i].push(x);
        }
    }
    vi mx,ans_mx;
    for(int i=0;i<n;i++){
        mx.push_back(num[i].top());
        ans+=num[i].top();
    }
    cout<<ans<<endl;
    bool b=0;
    for(const auto &i:mx)
        if(ans%i==0)
            ans_mx.push_back(i);
    if(!ans_mx.empty())
        cout<<ans_mx[0],b=1;
    for(int i=1;i<ans_mx.size();i++)
        cout<<" "<<ans_mx[i],b=1;
    if(!b)
        cout<<-1;
}