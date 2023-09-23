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

constexpr int N=2e5+5;
ll dp[N];

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        memset(dp,0,sizeof(dp));
        ll cnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='A')
                cnt++;
            else
                dp[i]=max(dp[i],cnt);
        }
        cnt=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='B')
                cnt++;
            else
                dp[i]=max(dp[i],cnt);
        }
        cnt=0;
        for(int i=0;i<s.size();i++)
            cnt+=dp[i];
        cout<<cnt<<endl;
    }
}