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

constexpr int cycle[] = {1, 5, 2, 8, 3, 9, 2, 8, 7, 7, 8, 4, 7, 3, 8, 4, 1, 5, 4, 4, 5, 9, 6, 2, 7, 3, 6, 2, 1, 1, 2, 8, 1, 7, 2, 8, 5, 9, 8, 8, 9, 3, 0, 6, 1, 7, 0, 6, 5, 5, 6, 2, 5, 1, 6, 2, 9, 3, 2, 2, 3, 7, 4, 0, 5, 1, 4, 0, 9, 9, 0, 6, 9, 5, 0, 6, 3, 7, 6, 6, 7, 1, 8, 4, 9, 5, 8, 4, 3, 3, 4, 0, 3, 9, 4, 0, 7, 1, 0, 0};

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    string s;
    while(cin>>s && s != "0"){
        string t = s.substr(max(0, (int)s.size() - 2), 2);
        int n = stoi(t);
        cout<<cycle[n - 1]<<endl;
    }
}