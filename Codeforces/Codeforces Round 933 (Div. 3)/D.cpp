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

int t,n,m,x,r;

inline int f(const int &cur,const int &d){
    if(cur+d>n)
        return cur+d-n;
    if(cur+d<=0)
        return n+(cur+d);
    return cur+d;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    char dir;
    cin>>t;
    while(t--){
        cin>>n>>m>>x;
        set<int> ans={x};
        for(int i=0;i<m;i++){
            set<int> t;
            cin>>r>>dir;
            for(const auto &j:ans){
                if(dir=='0')
                    t.emplace(f(j,r));
                else if(dir=='1')
                    t.emplace(f(j,-r));
                else
                    t.emplace(f(j,r)),t.emplace(f(j,-r));
            }
            ans=t;
        }
        cout<<ans.size()<<endl;
        for(const auto &i:ans)
            cout<<i<<" ";
        cout<<endl;
    }
}
/*
1
5 3 1
4 0
4 ?
1 ?
*/