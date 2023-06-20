//f505. 10603 - Fill
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

int a,b,c,d,t,answer[205];
bool visited[205][205];

struct Node{
    int x,y,z,ans;
    bool operator<(const Node& other) const{
        return ans>other.ans;
    }
};

void BFS(){
    priority_queue<Node> pq;

    pq.push({0,0,c,0});
    while(!pq.empty()){
        Node cur=pq.top();
        pq.pop();
        if(visited[cur.x][cur.y]){
            continue;
        }
        if(answer[cur.x]<0||cur.ans<answer[cur.x]){
            answer[cur.x]=cur.ans;
        }
        if(answer[cur.y]<0||cur.ans<answer[cur.y]){
            answer[cur.y]=cur.ans;
        }
        if(answer[cur.z]<0||cur.ans<answer[cur.z]){
            answer[cur.z]=cur.ans;
        }
        visited[cur.x][cur.y]=1;
        if(cur.x<b-cur.y) pq.push({0,cur.x+cur.y,cur.z,cur.ans+cur.x});
        else              pq.push({cur.x-(b-cur.y),b,cur.z,cur.ans+b-cur.y});
        if(cur.x<c-cur.z) pq.push({0,cur.y,cur.x+cur.z,cur.ans+cur.x});
        else              pq.push({cur.x-(c-cur.z),cur.y,c,cur.ans+c-cur.z});
        if(cur.y<a-cur.x) pq.push({cur.x+cur.y,0,cur.z,cur.ans+cur.y});
        else              pq.push({a,cur.y-(a-cur.x),cur.z,cur.ans+a-cur.x});
        if(cur.y<c-cur.z) pq.push({cur.x,0,cur.y+cur.z,cur.ans+cur.y});
        else              pq.push({cur.x,cur.y-(c-cur.z),c,cur.ans+c-cur.z});
        if(cur.z<a-cur.x) pq.push({cur.x+cur.z,cur.y,0,cur.ans+cur.z});
        else              pq.push({a,cur.y,cur.z-(a-cur.x),cur.ans+a-cur.x});
        if(cur.z<b-cur.y) pq.push({cur.x,cur.y+cur.z,0,cur.ans+cur.z});
        else              pq.push({cur.x,b,cur.z-(b-cur.y),cur.ans+b-cur.y});
    }
    while(d>=0){
        if(answer[d]>=0){
            printf("%d %d\n",answer[d],d);
            break;
        }
        d--;
    }
}

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d%d",&a,&b,&c,&d);
        memset(visited,0,sizeof(visited)),memset(answer,-1,sizeof(answer));
        BFS();
    }
}