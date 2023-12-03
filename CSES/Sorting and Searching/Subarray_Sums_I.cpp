//Subarray_Sums_I
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

int main(){//greedy 雙指針 滑動窗口
    ios::sync_with_stdio(0),cin.tie(0);
    int n,x;
    cin>>n>>x;
    vi num(n);
    for(auto &i:num)
        cin>>i;
    int l=0,r=0,sum=num[0],ans=0;
    while(l<=r&&r<n){
        if(sum<=x){
            if(sum==x)
                ans++;
            sum+=num[++r];
        }
        else if(l==r){
            l++,r++;
            sum=num[l];
        }
        else
            sum-=num[l++];
    }
    cout<<ans;
}