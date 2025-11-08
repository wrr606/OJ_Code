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

constexpr int MAXN = 10 + 2, MAXP = 1 << 11;
int n, m, p, atk = 0, ans = INT_MAX;
char mp[MAXN][MAXN];
int monsters_map[MAXN][MAXN], potions_map[MAXN][MAXN], dis[MAXN][MAXN][MAXP][2];
constexpr pii dir[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
vi potions;

class State{
public:
    int x, y;
    bool haveKey;
    int havePotions;

    State(int x, int y, bool haveKey, int havePotions):
        x(x), y(y), haveKey(haveKey), havePotions(havePotions){}
};

int BFS(const pii &start){
    //x     y      haveKey       stk        cost
    queue<State> que;
    que.emplace(start.first, start.second, 0, 0);
    dis[start.first][start.second][0][0] = 0;
    while(!que.empty()){
        State cur = move(que.front());
        que.pop();
        for(const auto &[xi, yi]: dir){
            auto [x, y, haveKey, havePotions] = cur;
            x += xi, y += yi;
            if((0 >= x || x > n || 0 >= y || y > n) ||
               mp[x][y] == '#'
            )   continue;
            haveKey = haveKey || (mp[x][y] == 'K');
            if(potions_map[x][y] != -1)
                havePotions |= (1 << potions_map[x][y]);
            int stk = 0;
            for(int i=0;i<p;i++){
                if((havePotions >> i) & 1)
                    stk += potions[i];
            }
            if(monsters_map[x][y] >= stk)
                continue;
            if(dis[x][y][havePotions][haveKey] == -1){
                dis[x][y][havePotions][haveKey] = dis[cur.x][cur.y][cur.havePotions][cur.haveKey] + 1;
                que.emplace(x, y, haveKey, havePotions);
            }
            if(mp[x][y] == 'E' && haveKey)
                return dis[x][y][havePotions][haveKey];
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>m>>p;
    pii start;
    memset(dis, -1, sizeof(dis));
    memset(monsters_map, -1, sizeof(monsters_map));
    memset(potions_map, -1, sizeof(potions_map));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>mp[i][j];
            if(mp[i][j] == 'S')
                start = {i, j};
        }
    }
    int x, y, val;
    for(int i=0;i<m;i++)
        cin>>x>>y>>val, monsters_map[x][y] = val;
    for(int i=0;i<p;i++)
        cin>>x>>y>>val, potions_map[x][y] = i, potions.emplace_back(val);
    cout<<BFS(start);
}
/*
5	1	4
E	.	. . .	
.	.	. . .	
.	#	K # .	
.	.	# . .	
.	.	. . S	
2	3	5	
2	2	1	
2	4	4	
4	2	2	
4	4	2	


4	4	1
S	.	. K	
.	.	. .	
.	.	. .	
E	.	. .	
1	3	7	
2	4	5	
3	1	2	
4	2	1	
4	3	5	

*/