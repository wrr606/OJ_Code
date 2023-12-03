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

const int N=2e5+5;
int n,num[N],prefix_sum[N];
ll prefix_product[N];

//差分
int d(const int &a,const int &b){
    return prefix_sum[b]-prefix_sum[a-1];
}

ll d_mul(const int &a,const int &b){
    return prefix_product[b]/prefix_product[a-1];
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int l,r;
        vi not1;
        ll product=1;
        bool f=0,ok=0;
        cin>>n;
        memset(prefix_sum,0,sizeof(prefix_sum));
        fill(prefix_product,prefix_product+n+1,1);
        for(int i=1;i<=n;i++){
            cin>>num[i];
            product*=num[i];
            prefix_sum[i]=num[i]+prefix_sum[i-1];
            prefix_product[i]=num[i]*prefix_product[i-1];
            if(product>=2*n)
                ok=1;
            if(num[i]!=1){
                not1.push_back(i);
                if(!f){
                    l=i;
                    f=1;
                }
                r=i;
            }
        }
        if(ok){
            cout<<l<<" "<<r<<endl;
            continue;
        }
        ll mx=-1,cur;
        pll pos={1,1};
        for(int i=0;i<not1.size();i++){
            for(int j=i;j<not1.size();j++){
                int a=not1[i],b=not1[j];
                cur=d(1,a-1)+d_mul(a,b)+d(b+1,n);
                if(cur>mx){
                    mx=cur;
                    pos={a,b};
                }
            }
        }
        cout<<pos.first<<" "<<pos.second<<endl;
    }
}