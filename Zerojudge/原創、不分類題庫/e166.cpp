//e166. 演唱會記行 - 粉絲應援
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

void move(deque<int> &num,const int &n){
    int temp=num[0];
    num.pop_front();
    num.push_back(temp);
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,x;
    while(cin>>n&&n){
        deque<int> num;
        for(int i=1;i<=n;i++)
            cin>>x,num.push_back(x);
        int mx=num[0];
        for(int i=0;i<n;i++){
            vi dp(all(num));
            for(int j=1;j<n;j++){
                if(dp[j-1]>=0)
                    dp[j]+=dp[j-1];
                mx=max(mx,dp[j]);
            }
            move(num,n);
        }
        cout<<mx<<endl;
    }
}