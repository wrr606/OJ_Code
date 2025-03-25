//k732. 2. 特殊位置
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

bool cmp(pii x,pii y){
    if(x.first==y.first)
        return x.second<y.second;
    return x.first<y.first;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<vector<int> > matrix(n,vector<int>(m));
    vector<pii> ans;
    for(auto &i:matrix)
        for(auto &j:i){
            cin>>j;
        }
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++){
            int sum=0;
            for(int k=0;k<matrix.size();k++){
                for(int l=0;l<matrix[k].size();l++){
                    if(abs(i-k)+abs(j-l)<=matrix[i][j]){
                        sum+=matrix[k][l];
                    }
                }
            }
            if(sum%10==matrix[i][j]){
                ans.push_back({i,j});
            }
        }
    }
    sort(all(ans),cmp);
    cout<<ans.size()<<endl;
    for(auto i:ans){
        cout<<i.first<<" "<<i.second<<endl;
    }
}