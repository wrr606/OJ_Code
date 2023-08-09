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

vvi earth(102,vi(102));

bool find_it=0;

void BFS(int x,int y){
    cout<<endl;
    queue<pii> que;
    que.push({x,y});
    while(!que.empty()){
        pii cur=que.front();
        que.pop();
        if(cur.first<=0||cur.first>100||cur.second<=0||cur.second>100||earth[cur.first][cur.second]==1)
            continue;
        if(earth[cur.first][cur.second]==-1){
            cout<<cur.first<<" "<<cur.second<<endl;
            find_it=1;
            return;
        }
        earth[cur.first][cur.second]=1;
        que.push({cur.first+1,cur.second});
        que.push({cur.first,cur.second+1});
        que.push({cur.first-1,cur.second});
        que.push({cur.first,cur.second-1});
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    earth[10][20]=-1;
    BFS(50,50);
    if(!find_it)
        cout<<0<<endl;
}