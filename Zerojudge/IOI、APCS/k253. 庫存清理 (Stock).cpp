//k253. 庫存清理 (Stock)
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int num,person,price,ans=0;
    cin>>num>>person>>price;
    int begin_num=num;
    for(int i=0;i<person;i++){
        if(num>=begin_num*0.8&&num<=begin_num){
            ans+=price*0.5;
            num--;
        }
        else if(num>=begin_num*0.6&&num<begin_num*0.8){
            num--;
            ans+=price*0.6;
        }
        else if(num>=begin_num*0.4&&num<begin_num*0.6){
            num--;
            ans+=price*0.8;
        }
        else if(num>=begin_num*0.2&&num<begin_num*0.4){
            num--;
            ans+=price*0.9;
        }
        else if(num<begin_num*0.2){
            break;
        }
    }
    cout<<ans<<endl;
}