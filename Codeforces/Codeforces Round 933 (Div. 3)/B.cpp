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

constexpr int N=2e5+5;
int x[N];

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>x[i];
        for(int l=0,r=n-1;l<=n-3;l++,r--){
            x[l+1]-=(x[l]<<1),x[l+2]-=x[l],x[l]=0;
            if(x[l+1]<0||x[l+2]<0)
                break;
            x[r-1]-=(x[r]<<1),x[r-2]-=x[r],x[r]=0;
            if(x[r-1]<0||x[r-2]<0)
                break;/*
            for(int i=0;i<n;i++)
                cout<<x[i]<<" ";cout<<endl;*/
        }
        if(count(x,x+n,0)==n)
            cout<<"yes\n";
        else
            cout<<"no\n";
    }
}
/*
1
6
5 6 0 2 3 0
*/