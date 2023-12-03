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

constexpr int N=1e7+5;
ll y[N]={1},x[N];

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,a,b,c,d;
    while(cin>>n&&n){
        cin>>a>>b>>c>>d;
        fill(y+1,y+1+n,0);
        y[0]=1;
        for(int i=1;i<=n;i++)
            y[i]=(y[i-1]*a+b)%c;
        for(int i=1;i<=n;i++)
            x[i]=y[i]%d-d/2;
        ll sum=0,mx=LONG_LONG_MIN,nega=1;
        pii range={1,1};
        for(int i=1;i<=n;i++){
            sum+=x[i];
            if(sum<0){
                nega=i;
                sum=0;
            }
            if(sum>mx){
                mx=sum;
                range={nega,i};
            }
        }
        cout<<mx<<" "<<range.first<<" "<<range.second<<endl;
    }
}