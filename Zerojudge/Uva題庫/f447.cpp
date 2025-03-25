#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,a,b;
    cin>>n;
    while(n--){
        cin>>a>>b;
        cout<<(2*b-a-1)*a/2<<endl;
    }
}