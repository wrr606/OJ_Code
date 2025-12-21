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

constexpr int MAXN = 1e5 + 5;
int n, arr[MAXN << 1];

int f(int cur){
    return arr[cur]==cur?cur:arr[cur]=f(arr[cur]);
}

void merge(int a,int b){
    a=f(a),b=f(b);
    if(a!=b){
        arr[b]=a;
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int q, op, a, b;
    cin>>n>>q;
    iota(arr, arr + (n + 1 << 1), 0);
    while(q--){
        cin>>op>>a>>b;
        if(op == 1){
            if(f(a) == f(b))
                cout<<"No\n";
            else{
                merge(a, b + n);
                merge(a + n, b);
            }
        }
        else{
            if(f(a) == f(b))
                cout<<"Same\n";
            else if(f(a) == f(b + n))
                cout<<"Different\n";
            else
                cout<<"Disconnected\n";
        }
    }
}