#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[5]={0}, n;    
    for(int i=1; i<=4; i++)
        for(int j=1; j<=4; j++) {cin>>n; a[i]+=n;}
    cout << a[1] << ":" << a[2] << "\n";
    cout << a[3] << ":" << a[4] << "\n";
    if     (a[1]>a[2] && a[3]>a[4]) cout<<"Win\n";
    else if(a[1]<a[2] && a[3]<a[4]) cout<<"Lose\n";
    else cout<<"Tie\n";
}