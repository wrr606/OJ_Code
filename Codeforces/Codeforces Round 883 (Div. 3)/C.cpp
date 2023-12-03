#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t,n,m,h;
    cin>>t;
    while(t--){
        cin>>n>>m>>h;
        vector<array<ll,3> > rank;
        for(int i=0;i<n;i++){
            vector<int> problems(m);
            for(auto &i:problems)
                cin>>i;
            sort(all(problems));
            ll sum=0,ans=0;
            int j=0;
            for(;j<m&&problems[j]+sum<=h;j++){
                sum+=problems[j];
                ans+=sum;
            }
            rank.push_back({-j,ans,i});
        }
        sort(all(rank));
        for(int i=0;i<n;i++){
            if(rank[i][2]==0){
                cout<<i+1<<endl;
                break;
            }
        }
    }
}