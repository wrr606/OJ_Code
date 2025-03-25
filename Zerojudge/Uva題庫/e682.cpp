//e682. 00531 - Compromise
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

int dp[105][105],path[105][105];

void print_ans(const vs &a,const vs &b){
    int la=a.size(),lb=b.size();
    vs ans;
    while(la&&lb){
        if(path[la][lb]==1){
            ans.push_back(a[la-1]);
            la--,lb--;
        }
        else if(path[la][lb]==2)
            la--;
        else
            lb--;
    }
    reverse(all(ans));
    for(const auto &i:ans)
        cout<<i<<" ";
    cout<<endl;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    string s;
    while(cin>>s){
        memset(dp,0,sizeof(dp)),memset(dp,0,sizeof(dp));
        string ans="";
        vs a,b;
        a.push_back(s);
        while(cin>>s&&s!="#")
            a.push_back(s);
        while(cin>>s&&s!="#")
            b.push_back(s);
        for(int i=1;i<=a.size();i++){
            for(int j=1;j<=b.size();j++){
                if(a[i-1]==b[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                    path[i][j]=1;
                }
                else if(dp[i][j-1]<dp[i-1][j]){
                    dp[i][j]=dp[i-1][j];
                    path[i][j]=2;
                }
                else{
                    dp[i][j]=dp[i][j-1];
                    path[i][j]=3;
                }
            }
        }
        print_ans(a,b);
    }
}