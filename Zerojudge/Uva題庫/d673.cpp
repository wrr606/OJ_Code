//d673. 11608 - No Problem
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
    int n,c=1,q[12],a[12];
    while(cin>>n&&n>=0){
        for(int i=0;i<12;i++)
            cin>>q[i];
        for(int i=0;i<12;i++)
            cin>>a[i];
        cout<<"Case "<<c++<<":\n";
        for(int i=0;i<12;i++){
            if(a[i]<=n){
                cout<<"No problem! :D\n";
                n-=a[i];
            }
            else
                cout<<"No problem. :(\n";
            n+=q[i];
        }
    }
}