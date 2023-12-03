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
    int n;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        unordered_set<int> check;
        int cur=0,cnt=s.size();
        while(cnt--&&!check.count(cur)){
            cerr<<s[cur]<<" ";
            check.insert(cur);
            int plus=int(s[cur]-48);
            if(cur+plus>=s.size()){
                cur=(cur+plus)%s.size();
            }
            else{
                cur+=plus;
            }
        }
        if(cnt==-1)
            cout<<"Yes\n";
        else
            cout<<"No\n";
        cerr<<cnt<<endl;
    }
}