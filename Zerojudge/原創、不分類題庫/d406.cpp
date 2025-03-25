//d406. 倒水時間
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

int s,n,m,mp[105][105],ans[105][105];

class Node{
public:
    int x,y,val;
    Node(const int &a,const int &b,const int &c){
        x=a,y=b,val=c;
    }
};

void BFS(const int &entrance){
    queue<Node> que;
    que.emplace(0,entrance,1);
    while(!que.empty()){
        auto cur=que.front();
        que.pop();
        if(cur.x < 0 || cur.x >= n || cur.y < 0 || cur.y >= m || !mp[cur.x][cur.y] || ans[cur.x][cur.y])
            continue;
        ans[cur.x][cur.y]=cur.val;
        que.emplace(cur.x,cur.y-1,cur.val+1);
        que.emplace(cur.x,cur.y+1,cur.val+1);
        que.emplace(cur.x+1,cur.y,cur.val+1);
        if(s == 1)
            que.emplace(cur.x-1,cur.y,cur.val+1);
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int cnt=1;
    while(cin>>s){
        cin>>n>>m;
        int entrance=0;
        for(int j=0;j<m;j++){
            cin>>mp[0][j];
            if(mp[0][j])
                entrance=j;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++)
                cin>>mp[i][j];
        }
        memset(ans,0,sizeof(ans));
        BFS(entrance);
        cout<<"Case "<<cnt++<<":\n";
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                cout<<ans[i][j]<<" ";
            cout<<endl;
        }
    }
}