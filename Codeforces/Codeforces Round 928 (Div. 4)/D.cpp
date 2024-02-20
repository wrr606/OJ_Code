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
    int t,n,x;
    cin>>t;
    while(t--){
        set<int> visited;
        cin>>n;
        int ans=0;
        map<int,int> cnt;
        for(int i=0;i<n;i++){
            cin>>x;
            cnt[x]++;
        }
        auto iter=cnt.begin();
        while(iter!=cnt.end()){
            if(visited.count(iter->first)){
                iter++;
                continue;
            }
            bitset<31> temp(iter->first);
            temp.flip();
            //cout<<iter->first<<" "<<iter->second<<" "<<temp.to_ulong()<<endl;
            if(cnt.count(temp.to_ulong())){
                visited.emplace(iter->first),visited.emplace(temp.to_ulong());
                ans+=max(iter->second,cnt[temp.to_ulong()]);
            }
            else
                ans+=iter->second;
            iter++;
        }
        cout<<ans<<endl;
    }
}
/*
3
0 2147483647 2147483647
1
5
476319172 261956880 2136179468 1671164475 1885526767

0011100011001000000110111000100 476319172
1100011100110111111001000111011 1671164475
0001111100111010010010100010000 261956880
1110000011000101101101011101111 1885526767
1111111010100111000001100001100 2136179468
*/