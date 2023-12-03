#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int x,modx,y,mody,z,modz;
    cin>>x>>modx>>y>>mody>>z>>modz;
    for(int i=1;i<=2000000;i++){
        if((i-modx)%x==0&&(i-mody)%y==0&&(i-modz)%z==0){
            cout<<i;
            break;
        }
    }
}

//Brute Force