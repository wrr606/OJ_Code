//k376. 求包含最大質因數的數
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t,n;
    cin>>t;
    int max=-1,ans;
    while(t--){
        cin>>n;
        int temp=n;
        for(int i=2;i<=sqrt(n);i+=(i==2)?1:2){
            while(temp%i==0){
                temp/=i;
            }
        }
        if(temp>max){
            max=temp;
            ans=n;
        }
    }
    cout<<ans<<endl;
}