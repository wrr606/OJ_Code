//k399. 取貨 (Pickup)
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
    string s;
    cin>>s;
    unordered_map<char,int> index;
    for(int i=0;i<s.size();i++){
        index[s[i]]=i;
    }
    vector<pair<char,int>> rank(all(index));
    sort(all(rank),[](pair<char,int> a,pair<char,int> b){
        return a.second<b.second;
    });
    for(int i=0;i<rank.size();i++)
        rank[i].second=i+1;
    sort(all(rank),[](pair<char,int> a,pair<char,int> b){
        return a.first<b.first;
    });
    for(const auto &i:rank)
        cout<<i.second;
}