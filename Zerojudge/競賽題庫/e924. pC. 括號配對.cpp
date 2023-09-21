//e924. pC. 括號配對
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

unordered_map<char,char> check={{'}','{'},{']','['},{')','('},{'>','<'}};

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    while(n--){
        string s;
        bool ok=1;
        cin>>s;
        vector<char> stk;
        for(const auto &i:s){
            if(check.count(i)){
                if(stk.empty()||stk.back()!=check[i]){
                    ok=0;
                    break;
                }
                else{
                    stk.pop_back();
                }
            }
            else
                stk.push_back(i);
        }
        if(ok&&stk.empty())
            cout<<"Y\n";
        else
            cout<<"N\n";
    }
}