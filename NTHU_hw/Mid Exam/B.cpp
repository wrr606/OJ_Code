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

constexpr int MAXN = 2e5 + 5;
int n, A[MAXN], B[MAXN];

int tableA[MAXN][32], tableB[MAXN][32];

void build(){
    for(int i=1;i<=n;i++)
        tableA[i][0]=A[i], tableB[i][0]=B[i];
    for(int k=1;k<32;k++){
        for(int i=1;i+(1<<(k-1))<=n;i++){
            tableA[i][k]=min(tableA[i][k-1], tableA[i+(1<<(k-1))][k-1]);
            tableB[i][k]=min(tableB[i][k-1], tableB[i+(1<<(k-1))][k-1]);
        }
    }
}

inline int query(int l, int r){
    const int idx=__lg(r-l+1);
    const int queryA = min(tableA[l][idx], tableA[r-(1<<idx)+1][idx]);
    const int queryB = min(tableB[l][idx], tableB[r-(1<<idx)+1][idx]);
    return queryA + queryB;
}

inline bool check(int x){
    if(x == 0)
        return 1;
    for(int l=1;l+x-1<=n;l++){
        if(query(l, l + x - 1) >= x)
            return 1;
    }
    return 0;
}

template <class Ty>
Ty find_max_true(Ty L, Ty R){
    while (L < R) {
        Ty mid = L + (R - L + 1) / 2;
        if (check(mid))
            L = mid;
        else
            R = mid - 1;
    }
    return L;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>A[i];
    for(int i=1;i<=n;i++)
        cin>>B[i];
    build();
    const int x = find_max_true(0, n);
    cout<<1LL* x * x<<endl;
}
/*
 5
 2 3 1 4 2
 3 2 2 1 3
 */