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

constexpr ll INF = 1e18;
class Item{
public:
    ll buy, sell;
    Item(ll buy, ll sell): buy(buy), sell(sell) {}
};
int n, m, k;

template <class Ty>
void Floyd_warshall(vector<vector<Ty>> &dp){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                dp[j][k]=min(dp[j][k], dp[j][i] + dp[i][k]);
            }
        }
    }
}

//符合條件的最大值
template <class Ty, class FuncTy>
Ty find_max_true(Ty L, Ty R, FuncTy check){
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
    int a, b, c;
    cin>>n>>m>>k;
    vector<vector<Item>> items(n + 1);
    for(int i=1;i<=n;i++){
        for(int j=0;j<k;j++){
            cin>>a>>b;
            items[i].emplace_back(a, b);
        }
    }
    vector<vll> mp(n + 1, vll(n + 1, INF)), profit(n + 1, vll(n + 1));
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        mp[a][b] = c;
    }
    Floyd_warshall(mp);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int item=0;item<k;item++){
                if(items[i][item].buy != -1 && items[j][item].sell != -1)
                    profit[i][j] = max(profit[i][j], items[j][item].sell - items[i][item].buy);
            }
        }
    }
    vector<vll> dp(n + 1, vll(n + 1));
    cout<<find_max_true(0, int(1e9), [&](int mid){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)
                dp[i][j] = mid * min(mp[i][j], 1LL * INF / mid) - profit[i][j];
        }
        Floyd_warshall(dp);
        for(int i=1;i<=n;i++){
            if(dp[i][i] <= 0){
                return 1;
            }
        }
        return 0;
    });
}