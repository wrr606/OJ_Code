//k932. 00834 - Continued Fractions
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

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int a,b,c,d=1;//a/b=c...d
    while(cin>>a>>b){
        vi ans;
        d=1;
        while(d){
            c=a/b;
            d=a%b;
            ans.push_back(c);
            a=b;
            b=d;
        }
        cout<<"["<<ans[0]<<";";
        for(int i=1;i<ans.size()-1;i++)
            cout<<ans[i]<<",";
        cout<<ans.back()<<"]\n";
    }
}