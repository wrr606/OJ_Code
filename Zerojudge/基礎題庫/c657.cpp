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

constexpr int MAXN = 1e5 + 5;

struct Node{
    char c;
    int cnt, t;
};

Node arr[MAXN];

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    string s;
    int idx, t;
    while(cin>>s){
        idx = 0, t = 0;
        arr[idx] = {s[0], 1, t};
        for(int i = 1; i < s.size(); i++){
            if(s[i] == s[i -1])
                ++arr[idx].cnt;
            else
                arr[++idx] = {s[i], 1, t};
        }
        sort(arr, arr + idx + 1, [](const Node &a, const Node &b){
            if(a.cnt == b.cnt){
                return a.t < b.t;
            }
            return a.cnt > b.cnt;
        });
        cout<<arr[0].c<<" "<<arr[0].cnt<<endl;
    }
}