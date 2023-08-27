//Road_Construction
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

const int N=100005;
int n,mx=1,heap;
int num[N];

int f(int cur){
    return num[cur]<0?cur:num[cur]=f(num[cur]);
}

void connect(int a,int b){
    a=f(a),b=f(b);
    if(a!=b){
        num[a]+=num[b];
        mx=max(mx,-num[a]);
        num[b]=a;
        heap--;
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int m;
    cin>>n>>m;
    memset(num,-1,sizeof(num));
    heap=n;
    while(m--){
        int a,b;
        cin>>a>>b;
        connect(a,b);
        cout<<heap<<" "<<mx<<endl;
    }
}