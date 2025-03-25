//e585. 12797 - Letters
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

struct point{
    int a,b,c;
};

vector<string> park;
deque<point> que;
bitset<150> limit;
int n,ans;

void BFS(){
    bool invited[102][102]={};
    que.clear();
    que.push_back({0,0,1});
    while(!que.empty()){
        auto iter=que.front();
        if(iter.a<0||iter.a>=n||iter.b<0||iter.b>=n){
            que.pop_front();
            continue;
        }
        if(limit[park[iter.a][iter.b]]||invited[iter.a][iter.b]){
            que.pop_front();
            continue;
        }
        invited[iter.a][iter.b]=1;
        if(iter.a==n-1&&iter.b==n-1){
            ans=min(ans,iter.c);
            return;
        }
        que.push_back({iter.a+1,iter.b,iter.c+1});
        que.push_back({iter.a,iter.b+1,iter.c+1});
        que.push_back({iter.a,iter.b-1,iter.c+1});
        que.push_back({iter.a-1,iter.b,iter.c+1});
        que.pop_front();
    }
}

void recursion(int i=0){
    if(i==10){
        BFS();
        return;
    }
    limit['a'+i]=1,limit['A'+i]=0;
    recursion(i+1);
    limit['a'+i]=0,limit['A'+i]=1;
    recursion(i+1);
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    string s;
    while(cin>>n){
        park.clear(),ans=INT_MAX;
        for(int i=0;i<n;i++){
            cin>>s;
            park.push_back(s);
        }
        recursion();
        if(ans!=INT_MAX)
            cout<<ans<<endl;
        else
            cout<<-1<<endl;
    }
}