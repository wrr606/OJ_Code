//d041. 11219 - How old are you?
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,ans,x1,x2;
    string now,burn;
    cin>>n;
    for(int counter=1;counter<=n;counter++){
        cin>>now>>burn;
        cout<<"Case #"<<counter<<": ";
        string y1="",y2="";
        for(int i=6;i<=9;i++){
            y1+=now[i];
            y2+=burn[i];
        }
        ans=stoi(y1)-stoi(y2);
        y1="",y2="";
        for(int i=3;i<=4;i++){
            y1+=now[i];
            y2+=burn[i];
        }
        x1=stoi(y1),x2=stoi(y2);
        if(x1<x2){
            ans--;
        }
        else if(x1==x2){
            y1="",y2="";
            for(int i=0;i<=1;i++){
                y1+=now[i];
                y2+=burn[i];
            }
            x1=stoi(y1),x2=stoi(y2);
            if(x1<x2){
            ans--;
            }
        }
        if(ans>130)
            cout<<"Check birth date\n";
        else if(ans<0)
            cout<<"Invalid birth date\n";
        else
            cout<<ans<<endl;
    }
}