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

constexpr ll mod = 1e9 + 7;
int n, m, k;

template <typename T>
struct Matrix
{
    using rt = std::vector<T>;
    using mt = std::vector<rt>;
    using matrix = Matrix<T>;
    int r, c;
    mt m;
    Matrix(int r, int c) : r(r), c(c), m(r, rt(c)) {}
    rt &operator[](int i) { return m[i]; }
    matrix operator*(const matrix &a)
    {
        matrix rev(r, a.c);
        matrix tmp(a.c, a.r);
        for (int i = 0; i < a.r; ++i)
            for (int j = 0; j < a.c; ++j)
                tmp[j][i] = a.m[i][j];
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < a.c; ++j)
                for (int k = 0; k < c; ++k)
                    rev.m[i][j] = ((rev.m[i][j] + ((m[i][k] * tmp[j][k]) % mod)) %mod);
        return rev;
    }
};

template <typename T>
Matrix<T> qpow(Matrix<T> a, int b){
    Matrix<T> res(n, n);
    for(int i=0;i<n;i++)
        res[i][i] = 1;
    while(b){
        if(b&1)
            res=res*a;
        b>>=1;
        a=a*a;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>m>>k;
    int a, b;
    Matrix<ll> adj(n, n);
    for(int i=0;i<m;i++){
        cin>>a>>b;
        adj[a - 1][b - 1]++;
    }
    auto ans = qpow(adj, k);
    cout<<ans[0][n - 1];
}