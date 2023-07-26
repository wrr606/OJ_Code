#include <bits/stdc++.h>
#define pb push_back
#define pii pair<int, int>
#define ff first
#define ss second
using namespace std;
struct rng{
    int l, r, t;
};
array<int, 200004> BIT, ans;
array<rng, 200004> R;
vector<pii> X, Y;
bool cmp(rng a, rng b){
    if(a.l != b.l) return a.l < b.l;
    return a.r > b.r;
}
void reset(){
    for(int &b : BIT) b = 0;
}
void update(int p){
    for(; p < 200004; p += p & -p){
        BIT[p]++;
    }
}
int query(int p){
    int sum = 0;
    for(; p > 0; p -= p & -p){
        sum += BIT[p];
    }
    return sum;
}
signed main(){
    int n, x, y, lst = 0, cnt = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        X.pb({x, i});
        Y.pb({y, i});
        R[i].t = i;
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    for(pii p : X){
        if(p.ff != lst) cnt++;
        R[p.ss].l = cnt;
        lst = p.ff;
    }
    lst = cnt = 0;
    for(pii p : Y){
        if(p.ff != lst) cnt++;
        R[p.ss].r = cnt;
        lst = p.ff;
    }
    sort(R.begin(), R.begin() + n, cmp);
    for(int i = n - 1; i >= 0; i--){
        ans[R[i].t] = query(R[i].r);
        update(R[i].r);
    }
    for(int i = 0; i < n; i++){
        cout << !!ans[i] << " ";
        ans[i] = 0;
    }
    cout << "\n";
    reset();
    for(int i = 0; i < n; i++){
        ans[R[i].t] = query(200001) - query(R[i].r - 1);
        update(R[i].r);
    }
    for(int i = 0; i < n; i++){
        cout << !!ans[i] << " ";
    }
    return 0;
}