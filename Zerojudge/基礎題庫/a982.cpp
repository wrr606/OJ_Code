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

constexpr pii dir[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int n;
char arr[101][101];
bool visited[101][101];

inline bool check(const int i, const int j){
    if(i < 0 || i >= n || j < 0 || j >= n || arr[i][j] == '#')
        return 0;
    return 1;
}

int BFS(){
    queue<array<int, 3>> que;
    que.push({1, 1, 0});
    while(!que.empty()){
        auto [i, j, dis] = que.front();
        que.pop();
        // cout<<i<<" "<<j<<endl;

        for(const auto &[x, y]: dir){
            i += x, j += y;
            if(check(i, j) && !visited[i][j]){
                que.push({i, j, dis + 1});
                visited[i][j] = 1;

                if(i == n - 2 && j == n - 2)
                    return dis + 2;
            }
            i -= x, j -= y;
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cin>>arr[i][j];
    }
    const int ans = BFS();
    cout<<(ans == -1 ? "No solution!" : to_string(ans));
}