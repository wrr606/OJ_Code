//k254. 拍七 (Seven)
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

bool havenum(int num,int now){
    string s=to_string(now);
    char temp=char(num+48);
    for(auto i:s)
        if(i==temp){
            return 1;
        }
    return 0;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int a,b,num,k,ans;
    cin>>a>>b>>num>>k;
    for(int i=a;i<=b;i++){
        if(!k)
            break;
        if(i%num==0)
            k--;
        else if(havenum(num,i))
            k--;
        ans=i;
    }
    if(k)
        cout<<-1<<endl;
    else
        cout<<ans<<endl;
}