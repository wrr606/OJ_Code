//b838. 104北二2.括號問題
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
    string s;
    cin>>n;
    getline(cin, s);
    for(int i=0;i<n;i++){
        getline(cin, s);
        vector<char> stk;
        int ans = 0;
        for(const auto &i:s){
            if(i == '('){
                stk.emplace_back(i);
            }
            else if(i == ')'){
                if(!stk.empty() && stk.back() == '(')
                    ++ans, stk.pop_back();
                else{
                    stk.emplace_back(i);
                    break;
                }
            }
        }
        if(stk.empty())
            cout<<ans<<endl;
        else
            cout<<0<<endl;
    }
}