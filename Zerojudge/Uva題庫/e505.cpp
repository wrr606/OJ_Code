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
    int n, x, y;
    cin>>n;
    string s, ss;
    while(n--){
        cin>>s;
        ss = s.substr(4, 4);
        x = (s[0] - 'A') * 26 * 26 + (s[1] - 'A') * 26 + (s[2] - 'A');
        y = stoi(ss);
        if(abs(x - y) <= 100)
            cout<<"nice\n";
        else
            cout<<"not nice\n";
    }
}