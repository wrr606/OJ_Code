//j125. 4. 蓋步道
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

int matrix[305][305],dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}},n,mx=INT_MIN;
bool visited[305][305];

int BFS(int highest){//尋找最短路徑
    memset(visited,0,sizeof(visited));
    queue<array<int,3>> que;
    que.push({0,0,0});
    while(!que.empty()){
        auto cur=que.front();
        que.pop();
        for(int i=0;i<4;i++){
            int x=cur[0]+dir[i][0],y=cur[1]+dir[i][1];
            if(x<0||x>=n||y<0||y>=n||visited[x][y]||abs(matrix[x][y]-matrix[cur[0]][cur[1]])>highest)
                continue;
            visited[x][y]=1;
            if(x==n-1&&y==n-1)
                return cur[2]+1;
            que.push({x,y,cur[2]+1});
        }
    }
}

bool DFS(int high){//判斷當前的高度差能否抵達終點
    memset(visited,0,sizeof(visited));
    vector<pii> stk={{0,0}};
    while(!stk.empty()){
        pii cur=stk.back();
        stk.pop_back();
        for(int i=0;i<4;i++){
            int x=cur.first+dir[i][0],y=cur.second+dir[i][1];
            if(x<0||x>=n||y<0||y>=n||visited[x][y]||abs(matrix[x][y]-matrix[cur.first][cur.second])>high)
                continue;
            visited[x][y]=1;
            if(x==n-1&&y==n-1)
                return 1;
            stk.push_back({x,y});
        }
    }
    return 0;
}

int find_highest(){//二分搜 upper_bound高度差
    int l=0,r=1e6,mid;
    while(l<r){
        mid=l+((r-l)>>1);
        bool can=DFS(mid);
        if(can)
            r=mid;
        else
            l=mid+1;
        cout<<l<<" "<<mid<<" "<<r<<endl;
    }
    return r;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
            mx=max(mx,matrix[i][j]);
        }
    }
    int highest=find_highest();
    cout<<highest<<endl<<BFS(highest)<<endl;
}
/*
4
8 8 6 7
4 9 3 2
9 3 1 8
4 7 1 7

*/