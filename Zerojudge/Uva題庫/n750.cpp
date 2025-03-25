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

int n;
vector<vector<int>> ans;
vector<int> t;

void f(int m=n){
    if(m==1 && t.size()>1){
        ans.push_back(t);
        return;
    }
    int last=t.empty()?2:t.back();
    for(int i=last;i<=m;i++){
        if(m%i==0){
            t.push_back(i);
            f(m/i);
            t.pop_back();
        }
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    while(cin>>n && n){
        ans.clear();
        f();
        cout<<ans.size()<<endl;
        for(const auto &i:ans){
            for(const auto &j:i)
                cout<<j<<" ";
            cout<<endl;
        }
    }
}