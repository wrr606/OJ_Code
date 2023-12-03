//d543. 挑战极限 Part7：强大的N皇后
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

int n,queen[21],invited[3][99999],ans;

void search(int now=0){
    if(now==n)
        ans++;
    else
        for(int i=0;i<n;i++){
            if(!invited[0][i]&&!invited[1][now+i]&&!invited[2][now-i+n]){
                queen[now]=i;
                invited[0][i]=invited[1][now+i]=invited[2][now-i+n]=1;
                search(now+1);
                invited[0][i]=invited[1][now+i]=invited[2][now-i+n]=0;
            }
        }       
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    while(cin>>n){
        ans=0;
        search();
        cout<<ans<<endl;
    }
}