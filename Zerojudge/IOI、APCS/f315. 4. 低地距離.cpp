//f315. 4. 低地距離
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

class Binary_Indexed_Tree{
private:
    vi BIT;
    int n;
public:
    Binary_Indexed_Tree(int size){
        n=size;
        BIT.assign(size+1,0);
    }

    int query(int idx){
        int res=0;
        while(idx>0){
            res+=BIT[idx];
            idx-=(idx&-idx);
        }
        return res;
    }

    void update_add(int idx,int val){
        while(idx<=n){
            BIT[idx]+=val;
            idx+=(idx&-idx);
        }
    }
};

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,temp;
    cin>>n;
    Binary_Indexed_Tree BIT(n<<1);
    bitset<200005> check;
    vector<pii> site(n+1);
    for(int i=1;i<=n<<1;i++){
        cin>>temp;
        if(check[temp])
            site[temp].second=i;
        else
            site[temp].first=i;
        check[temp]=1;
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        ans+=BIT.query(site[i].second)-BIT.query(site[i].first-1);
        BIT.update_add(site[i].first,1);
        BIT.update_add(site[i].second,1);
    }
    cout<<ans;
}