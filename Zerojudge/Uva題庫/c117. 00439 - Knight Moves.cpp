//c117. 00439 - Knight Moves
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

string starting,ending,temp;
deque<pair<string,int> > que;
int invited[200][99];

void BFS(){
    while(!que.empty()){
        auto iter=que.front();
        if(iter.first[0]<'a'||iter.first[0]>'h'||iter.first[1]<'1'||iter.first[1]>'8'){
            que.pop_front();
            continue;
        }
        else if(invited[iter.first[0]][iter.first[1]]){
            que.pop_front();
            continue;
        }
        invited[iter.first[0]][iter.first[1]]=iter.second;
        temp=iter.first;
        temp[0]+=1,temp[1]+=2;
        que.push_back({temp,iter.second+1});
        temp=iter.first;
        temp[0]+=1,temp[1]-=2;
        que.push_back({temp,iter.second+1});
        temp=iter.first;
        temp[0]+=2,temp[1]+=1;
        que.push_back({temp,iter.second+1});
        temp=iter.first;
        temp[0]+=2,temp[1]-=1;
        que.push_back({temp,iter.second+1});

        temp=iter.first;
        temp[0]-=1,temp[1]+=2;
        que.push_back({temp,iter.second+1});
        temp=iter.first;
        temp[0]-=1,temp[1]-=2;
        que.push_back({temp,iter.second+1});
        temp=iter.first;
        temp[0]-=2,temp[1]+=1;
        que.push_back({temp,iter.second+1});
        temp=iter.first;
        temp[0]-=2,temp[1]-=1;
        que.push_back({temp,iter.second+1});
        que.pop_front();
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    while(cin>>starting){
        cin>>ending;
        cout<<"To get from "<<starting<<" to "<<ending<<" takes ";
        if(ending==starting){
            cout<<0<<" knight moves.\n";
            continue;
        }
        memset(invited,0,sizeof(invited)),que.clear(),que.push_back({starting,0});
        BFS();
        cout<<invited[ending[0]][ending[1]]<<" knight moves.\n";
    }
}