//d794. 世界排名
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
typedef tree<ll,null_type,greater<ll>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<ll,null_type,greater_equal<ll>,rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    while(cin>>n){
        ll num;
        ordered_set grades;
        while(n--){
            cin>>num;
            cout<<grades.order_of_key(num)+1<<endl;
            grades.insert(num);
        }
    }
}