//f291. 試算表大小
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

int mod_26(const string &s){
    int res=0;
    for(const auto &i:s){
        if(isdigit(i))
            return res;
        else
            res=res*26+int(i)-'A'+1;
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(isdigit(s[i])){
            cout<<mod_26(s)*stoi(s.substr(i));
            break;
        }
    }
}