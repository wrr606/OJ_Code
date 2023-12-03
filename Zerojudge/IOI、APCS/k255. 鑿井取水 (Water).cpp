//k255. 鑿井取水 (Water)
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t,w,person,water=0,dry=-1;
    bool again=1;
    cin>>t>>w;
    for(int i=1;i<=t;i++){
        water+=w;
        cin>>person;
        int sum=0,temp;
        for(int j=0;j<person;j++){
            cin>>temp;
            sum+=temp;
        }
        water-=sum;
        if(water<0&&again){
            dry=i,again=0;
        }
    }
    cout<<dry<<endl;
}