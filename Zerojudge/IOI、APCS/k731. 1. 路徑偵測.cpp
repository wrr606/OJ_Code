//k731. 1. 路徑偵測
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int dir=1,x=0,y=0,a,b,t,l=0,r=0,re=0;
    cin>>t;
    while(t--){
        cin>>a>>b;
        //cout<<x<<" "<<y<<endl;
        if(dir==1){
            if(x-a==0&&y-b>0){
                dir=2,r++;
            }
            if(x-a==0&&y-b<0){
                dir=4,l++;
            }
            if(x-a>0&&y-b==0){
                dir=3,re++;
            }
        }
        else if(dir==2){
            if(x-a>0&&y-b==0){
                dir=3,r++;
            }
            if(x-a<0&&y-b==0){
                dir=1,l++;
            }
            if(x-a==0&&y-b<0){
                dir=4,re++;
            }
        }
        else if(dir==3){
            if(x-a==0&&y-b<0){
                dir=4,r++;
            }
            if(x-a==0&&y-b>0){
                dir=2,l++;
            }
            if(x-a<0&&y-b==0){
                dir=1,re++;
            }
        }
        else if(dir==4){
            if(x-a>0&&y-b==0){
                dir=3,l++;
            }
            if(x-a<0&&y-b==0){
                dir=1,r++;
            }
            if(x-a==0&&y-b>0){
                dir=2,re++;
            }
        }
        x=a,y=b;
        cout<<dir<<endl;
    }
    cout<<l<<" "<<r<<" "<<re<<endl;
}