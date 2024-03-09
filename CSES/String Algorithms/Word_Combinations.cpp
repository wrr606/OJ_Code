//Word Combinations
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

struct TrieNode {
    int nxt[26]; //遇到a~z時的節點編號(idx)
    int cnt; //以此結尾的字串個數
} node[1000005];
int idx = 2; //root = 1

void insert(string_view s){
     int cur = 1; //從root開始
     for(auto i:s) {
          if(node[cur].nxt[i-'a'] == 0){
               node[cur].nxt[i-'a'] = idx; //開一個新的node
               cur = idx;
               idx++;
           }
           else {
                cur = node[cur].nxt[i-'a'];
           }
     }
     node[cur].cnt++;
}

int query(string_view s){
     int cur = 1;
     for(auto i:s) {
          if(node[cur].nxt[i-'a'] == 0){
               return 0;
           }
           else {
                cur = node[cur].nxt[i-'a'];
           }
     }
     return node[cur].cnt;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    insert("abcdefg");
    cout<<query("abcdefg");
}