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

vvi pre;
string s1, s2;

void print(int i=s1.size(), int j=s2.size()){
    if(!i || !j)
        return;
    if(pre[i][j] == 0){
        print(i-1,j-1);
        cout<<s1[i-1];
    }
    else if(pre[i][j] == 1){
        print(i, j-1);
    }
    else if(pre[i][j] == 2){
        print(i-1, j);
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>s1>>s2;
    vvi dp(s1.size() + 1, vi(s2.size() + 1));
    pre = dp;
    for(int i=1;i<=s1.size();i++){
        for(int j=1;j<=s2.size();j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
                pre[i][j]=0;//左上
            }
            else{
                if(dp[i-1][j] < dp[i][j-1]){
                    dp[i][j] = dp[i][j-1];
                    pre[i][j]=1;//左
                }
                else{
                    dp[i][j] = dp[i-1][j];
                    pre[i][j]=2;//上
                }
            }
        }
    }
    print();
}