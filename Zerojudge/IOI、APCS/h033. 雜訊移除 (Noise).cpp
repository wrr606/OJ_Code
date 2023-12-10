//h033. 雜訊移除 (Noise)
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

string check(const vector<char> &ans){
    for(int i=0;i<(ans.size()>>1);i++)
        if(ans[i]!=ans[ans.size()-1-i])
            return "No";
    return "Yes";
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    string s;
    char c;
    cin>>s>>c;
    vector<char> ans;
    for(const auto &i:s){
        if(i!=c)
            ans.push_back(i);
    }
    cout<<check(ans);
}