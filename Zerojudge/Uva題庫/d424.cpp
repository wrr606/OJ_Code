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

constexpr int MAXN = 1e4 + 5;
int arr[MAXN];

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int l, h, r;
    int L = INT_MAX, R = INT_MIN;
    while(cin>>l>>h>>r){
        for(int i = l; i < r; i++)
            arr[i] = max(arr[i], h);
        L = min(L, l);
        R = max(R, r);
    }
    int last = -1;
    for(int i = L; i <= R; i++){
        if(arr[i] != last){
            cout<<i<<" "<<arr[i]<<" ";
            last = arr[i];
        }
    }
}