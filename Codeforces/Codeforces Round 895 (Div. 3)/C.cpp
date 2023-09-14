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

int is_prime(int n){
    for(int i=2;i*i<=n;i+=(i==2)?1:2){
        if(n%i==0)
            return i;
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int l,r,temp;
        cin>>l>>r;
        bool ok=0;
        for(int i=l;i<=r;i++){
            temp=is_prime(i);
            if(temp){
                cout<<temp<<" "<<i-temp<<endl;
                ok=1;
                break;
            }
        }
        if(!ok)
            cout<<-1<<endl;
    }
}