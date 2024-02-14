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
        cin>>n;
        int avg=0;
        for(int c=0;c<n;c++){
            cin>>x[c];
            avg+=x[c];
        }
        avg/=n;
        bool ok=1;
        for(int i=0;i<n-1;i++){
            if(x[i]>avg)
                x[i+1]+=x[i]-avg;
            else if(x[i]<avg){
                cout<<"NO\n";
                ok=0;
                break;
            }
        }
        if(ok)
            cout<<"YES\n";/*
        for(int i=0;i<n;i++)
            cout<<x[i]<<" ";*/
    }
}