//d277. 矩形对角线
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    while(cin>>n){
        if(n&1)
            cout<<n-1<<endl;
        else
            cout<<n<<endl;
    }
}