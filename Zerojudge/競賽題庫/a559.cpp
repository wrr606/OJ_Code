//a559. NCPC PC Matrix
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
    int t,n,m,temp;
    cin>>t;
    while(t--){
        cin>>m>>n;
        vvi matrix(m,vi(n));
        int mx=-1;
        for(auto &i:matrix){
            for(auto &j:i)
                cin>>j;
            sort(all(i));
        }
        sort(all(matrix));
        vi dp(m+1,1);
        for(int i=1;i<m;i++){
            for(int j=0;j<i;j++){
                bool ok=1;
                for(int k=0;k<n;k++){
                    if(matrix[i][k]<=matrix[j][k]){
                        ok=0;
                        break;
                    }
                }
                if(ok)
                    dp[i]=max(dp[i],dp[j]+1);
            }
        }
        cout<<*max_element(all(dp))<<endl;
    }
}