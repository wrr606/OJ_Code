//Sum_of_Four_Values
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
typedef vector<vector<int> > vvi;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,x;
    cin>>n>>x;
    vi num(n);
    unordered_map<int,pii> check;
    for(auto &i:num)
        cin>>i;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            check[num[i]+num[j]]={i,j};
        }
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            int sum=x-num[i]-num[j];
            if(check.count(sum)){
                if(check[sum].first!=i&&check[sum].second!=j&&check[sum].first!=j&&check[sum].second!=i){
                    cout<<i+1<<" "<<j+1<<" "<<check[sum].first+1<<" "<<check[sum].second+1<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<"IMPOSSIBLE\n";
}