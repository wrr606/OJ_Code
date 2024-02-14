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
    int t,n;
    string s="aaa";
    vs tp;
    for(int i=0;i<26;i++){
        s[0]='a'+i;
        for(int j=0;j<26;j++){
            s[1]='a'+j;
            for(int k=0;k<26;k++){
                s[2]='a'+k;
                tp.push_back(s);
            }
        }
    }
    cin>>t;
    while(t--){
        cin>>n;
        for(const auto &i:tp){
            if(n==i[0]+i[1]+i[2]-'a'*3+3){
                cout<<i<<endl;
                break;;
            }
        }
    }
}