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
    int t;
    cin>>t;
    while(t--){
        string s;
        vector<pair<int,char>> mn,mx,ans;
        cin>>s;
        for(int i=0;i<s.size();i++){
            if(s[i]=='B'){
                if(!mx.empty())
                    mx.pop_back();
            }
            else if(s[i]=='b'){
                if(!mn.empty())
                    mn.pop_back();
            }
            else if('A'<=s[i]&&s[i]<='Z')
                mx.push_back({i,s[i]});
            else
                mn.push_back({i,s[i]});
        }
        ans=mx;
        for(const auto &i:mn)
            ans.push_back(i);
        sort(all(ans));
        for(const auto &i:ans)
            cout<<i.second;
        cout<<endl;
    }
}