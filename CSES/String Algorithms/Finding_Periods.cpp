//Finding Periods
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

inline void zfunction(string_view s){
    vi z(s.size());
    for (int i = 1, l = 0, r = 0; i < s.size(); ++i) {
        if (z[i - l] < r - i + 1)
            z[i] = z[i - l];
        else {
            z[i] = max(r - i + 1, 0);
            while (i + z[i] < s.size() && s[z[i]] == s[i + z[i]])
                z[i]++;
            l = i, r = i + z[i] - 1;
        }
        if(i+z[i]==s.size())
            cout<<i<<" ";
    }
    cout<<s.size();
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    string s;
    cin>>s;
    zfunction(s);
}