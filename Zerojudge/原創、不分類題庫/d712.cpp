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

typedef unsigned long long int ull;
constexpr int MAXN = 1e6 + 1;
int n, m;
ull dp[MAXN] = {0, 1};

class SegmentTree{
private:
    ull* tree;

    void merge(int idx){
        tree[idx] = max(tree[idx<<1], tree[idx<<1|1]);
        //區間最大要把return x+y改成max(x,y)
    }

    void build(int l, int r, int idx = 1){//創建線段樹
        if(l==r){
            tree[idx] = dp[l];
            return;
        }
        int mid=(l+r)>>1;
        build(l, mid, idx << 1);
        build(mid + 1, r, idx << 1 | 1);
        merge(idx);
    }

    ull query(int ql, int qr, int l, int r, int idx = 1){//區間查詢
        //ql~qr為欲查詢的範圍
        if(ql<=l&&r<=qr)
            return tree[idx];
        int mid=(l+r)>>1;
        if(mid>=qr)
            return query(ql, qr, l, mid, idx << 1);
        else if(ql>mid)
            return query(ql, qr, mid + 1, r, idx << 1 | 1);
        else
            return max(query(ql, qr, l, mid, idx << 1), query(ql, qr, mid + 1, r, idx << 1 | 1));
            //區間最大要把return x+y改成max(x,y)
    }

public:
    ull query(int l, int r){
        return query(l, r, 1, MAXN - 1);
    }

    SegmentTree(){
        tree = new ull[MAXN + 5 << 2]();
        build(1, MAXN - 1);
    }
};

void init(){
    for(ull i = 2, t, cnt; i < MAXN; i++){
        t = i, cnt = 0;
        if(i % 2 == 0){
            dp[i] = dp[i >> 1] + 1;
            continue;
        }
        while(t >= i){
            if(t & 1){
                cnt += 2;
                t = 3 * t + 1 >> 1;
            }
            else{
                ++cnt;
                t >>= 1;
            }
        }
        dp[i] = dp[t] + cnt;
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    init();
    SegmentTree st;
    while(cin>>n>>m){
        cout<<n<<" "<<m<<" ";
        cout<<st.query(min(n, m), max(n, m))<<endl;
    }
}