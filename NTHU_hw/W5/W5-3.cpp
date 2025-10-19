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
    int n;
    cin>>n;
    vector<pii> num(n),stk;
    for(int i=0;i<n;i++)
        cin>>num[i].first,num[i].second=i;
    for(const auto &i:num){
        while(!stk.empty()&&stk.back().first>=i.first){
            stk.pop_back();
        }
        if(stk.empty())
            cout<<"0 ";
        else
            cout<<stk.back().second+1<<" ";
        stk.push_back(i);
    }
}