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
        int a=0,b=0,c=0,n;
        cin>>n;
        string s,t(n+1,'0');
        cin>>s;
        for(int i=0;i<n/2;i++){
            if(s[i]==s[s.size()-i-1])
                a++;
            else
                b++;
        }
        if(n&1)
            c++;
        for(int i=0;i<=a;i++){
            for(int j=0;j<=c;j++){
                t[b+(i<<1)+j]='1';
            }
        }
        cout<<t<<endl;
    }
}