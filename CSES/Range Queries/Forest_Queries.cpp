//Forest_Queries
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
    int n,q;
    cin>>n>>q;
    vvi prefix(n+1,vi(n+1));
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        for(int j=1;j<=n;j++){
            prefix[i][j]+=prefix[i][j-1];
            if(s[j-1]=='*'){
                prefix[i][j]++;
            }
        }
        for(int j=1;j<=n;j++){
            prefix[i][j]+=prefix[i-1][j];
        }
    }
    while(q--){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        cout<<prefix[x2][y2]-prefix[x1-1][y2]-prefix[x2][y1-1]+prefix[x1-1][y1-1]<<endl;
    }
}