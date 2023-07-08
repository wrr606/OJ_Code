#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

struct member{
    int a,b,c;
};

bool cmp(member x,member y){
    if(x.b==y.b)
        return x.c<y.c;
    return x.b>y.b;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t,n,m,h;
    cin>>t;
    while(t--){
        cin>>n>>m>>h;
        vector<vector<int> > person(n,vector<int>(m));
        vector<int> time(n,h),score(n),reverse_score(n);
        for(auto &i:person)
            for(auto &j:i)
                cin>>j;
        for(auto &i:person)
            sort(all(i));
        vector<vector<int> > sum(n,vector<int>(m));
        for(int i=0;i<n;i++)
            sum[i][0]=person[i][0];
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                sum[i][j]=sum[i][j-1]+person[i][j];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(time[i]>=person[i][j]){
                    reverse_score[i]+=sum[i][j];
                    //cout<<reverse_score[i]<<' '<<sum[i][j]<<endl;
                    time[i]-=person[i][j];
                    score[i]++;
                }
                else
                    break;
            }
        }
        vector<member> rank;
        for(int i=0;i<n;i++){
            rank.push_back({i,score[i],reverse_score[i]});
        }
        sort(all(rank),cmp);/*
        for(auto i:rank)
            cout<<i.a<<" "<<i.b<<" "<<i.c<<endl;*/
        for(int i=0;i<n;i++){
            if(rank[i].a==0){
                cout<<i+1<<endl;
                break;
            }
        }
    }
}