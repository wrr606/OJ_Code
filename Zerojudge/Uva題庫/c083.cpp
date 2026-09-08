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

int n, k;

int test(const int init){
    vi arr(n);
    iota(all(arr), 1);
    int idx = init - 1;
    
    while(arr.size() > 1){
        const int kill_idx = (idx + k - 1) % arr.size();
        arr.erase(arr.begin() + kill_idx);

        const int bury_idx = (kill_idx + k - 1) % arr.size();
        const int burying = arr[bury_idx];
        arr.erase(arr.begin() + bury_idx);

        int insert_idx = kill_idx;
        if(bury_idx < kill_idx)
            insert_idx--;
        arr.insert(arr.begin() + insert_idx, burying);

        idx = (insert_idx + 1) % arr.size();

        // for(auto i:arr)
        //     cout<<i<<" ";cout<<endl;
    }

    return arr[0];
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);

    while(cin>>n>>k && n && k){
        for(int i = 1; i <= n; i++){
            const int ans = test(i);
            if(ans == 1){
                cout<<i<<endl;
                break;
            }
        }
    }
}