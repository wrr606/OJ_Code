//a465. 12405 - Scarecrow
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
    int t;
    cin>>t;
    for(int c=1;c<=t;c++){
        bitset<105> check;
        int n,ans=0;
        string s;
        cin>>n>>s;
        for(int i=0;i<n;i++){
            if(s[i]=='.'&&!check[i]){
                ans++;
                check[i]=1;
                check[i+1]=1;
                check[i+2]=1;
            }
        }
        cout<<"Case "<<c<<": "<<ans<<endl;
    }
}