//Increasing_Subsequence
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

int main(){//LIS
    ios::sync_with_stdio(0),cin.tie(0);
    int n,num;
    cin>>n;
    vi lis;
    for(int i=0;i<n;i++){
        cin>>num;
        if(lis.empty()||lis.back()<num)
            lis.push_back(num);
        else
            *lower_bound(all(lis),num)=num;
    }
    cout<<lis.size();
}