//Factory_Machines
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

ll binary_search(vi &num,int t){
    ll l=1,r=ll(*max_element(all(num)))*t,mid,res;
    while(l<=r){
        mid=l+(r-l)/2;
        unsigned long long int products=0;
        for(const auto &i:num)
            products+=mid/i;
        if(products>=t)
            res=mid,r=mid-1;
        else
            l=mid+1;
    }
    return res;
}

int main(){//二分搜
    ios::sync_with_stdio(0),cin.tie(0);
    int n,t;
    cin>>n>>t;
    vi num(n);
    for(auto &i:num)
        cin>>i;
    cout<<binary_search(num,t);
}