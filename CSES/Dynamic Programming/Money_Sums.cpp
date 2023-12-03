//Money_Sums
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

bitset<1000001> dp;

int main(){//01背包
    ios::sync_with_stdio(0),cin.tie(0);
    int n,sum=0;
    cin>>n;
    vi num(n);
    for(auto &i:num)
        cin>>i,sum+=i;
    dp[0]=1;
    for(const auto &i:num){
        for(int j=sum;j>=i;j--){
            if(!dp[j])
                dp[j]=dp[j-i];
        }
    }
    cout<<dp.count()-1<<endl;
    for(int i=1;i<=sum;i++)
        if(dp[i])
            cout<<i<<" ";
}