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

constexpr int N=2e5;
int x[N];

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;//1 1 1
        bool equal=1;
        cin>>x[0];
        for(int c=1;c<n;c++){
            cin>>x[c];
            if(equal&&x[0]!=x[c])
                equal=0;
        }
        if(equal){
            cout<<0<<endl;
            continue;
        }
        int l=0,r=0;
        for(int i=0;i<n;i++){
            if(x[i]==x[0])
                l++;
            else
                break;
        }
        for(int i=n-1;i>=0;i--){
            if(x[i]==x[n-1])
                r++;
            else
                break;
        }
        if(x[0]==x[n-1])
            l+=r,r=0;
        cout<<n-max(l,r)<<endl;
    }
}