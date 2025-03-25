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

void f(pdd &node, const int &d){
    auto &[x, y]=node;
    int t=sqrt(double(d*d-y*y));
    y=x+t;
    x=x-t;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n, d, c=0;
    while(cin>>n>>d && n && d){
        vector<pdd> node(n);
        bool no_ans=0;
        for(auto &i:node){
            cin>>i.first>>i.second;
            if(i.second>d)
                no_ans=1;
            f(i, d);
        }
        sort(all(node), [](const pdd &a, const pdd &b){
            return a.second<b.second;
        });
        int ans=0, cur=INT_MIN;
        for(const auto &[l, r]:node){
            if(l<=cur)
                continue;
            ans++;
            cur=r;
        }
        cout<<"Case "<<++c<<": ";
        if(no_ans)
            cout<<-1<<endl;
        else
            cout<<ans<<endl;
    }
}