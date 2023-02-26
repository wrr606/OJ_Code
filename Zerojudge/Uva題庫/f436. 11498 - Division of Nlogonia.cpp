#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t,n,m,x,y,dx,dy;
    while(cin>>t&&t){
        cin>>n>>m;
        for(int o=0;o<t;o++){
            cin>>x>>y;
            dx=x-n;
            dy=y-m;
            if(!dx||!dy)
                cout<<"divisa\n";
            else if(dx>0&&dy>0)
                cout<<"NE\n";
            else if(dx<0&&dy>0)
                cout<<"NO\n";
            else if(dx<0&&dy<0)
                cout<<"SO\n";
            else
                cout<<"SE\n";
        }
    }
}