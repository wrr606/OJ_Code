//i644. 列舉八皇后問題所有解
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

int n=8,queen[10]={},invited[3][100]={};
set<string> ans;

void search(int now=1){
    if(now>n){
        string s="";
        for(int i=1;i<=n;i++){
            s+=char(48+queen[i]);
        }
        ans.insert(s);
    }
    else
        for(int i=1;i<=n;i++){
            if(!invited[0][i]&&!invited[1][i+now]&&!invited[2][now-i+n]){
                queen[now]=i;
                invited[0][i]=invited[1][i+now]=invited[2][now-i+n]=1;
                search(now+1);
                invited[0][i]=invited[1][i+now]=invited[2][now-i+n]=0;
            }
        }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    search();
    int counter=1;
    for(auto i:ans){
        cout<<counter<<": "<<i<<endl;
        counter++;
    }
}