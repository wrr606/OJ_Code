//Salary_Queries
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
typedef tree<pii,null_type,less<pii>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<pii,null_type,less_equal<pii>,rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,q;
    ordered_set salary;
    cin>>n>>q;
    vi num(n+1);
    for(int i=1;i<=n;i++){
        cin>>num[i];
        salary.insert({num[i],i});
    }
    char op;
    while(q--){
        int a,b;
        cin>>op>>a>>b;
        if(op=='!'){
            salary.erase({num[a],a});
            num[a]=b;
            salary.insert({num[a],a});
        }
        else{
            auto x=salary.order_of_key({a-1,INT_MAX}),y=salary.order_of_key({b,INT_MAX});
            cout<<y-x<<endl;
        }
    }
}