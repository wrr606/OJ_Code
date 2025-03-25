//g488. COVID-101
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

int n(int x){
    if(x==1)
        return 1;
    else{
        return n(x-1)+x*x-x+1;
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int x;
    cin>>x;
    cout<<n(x)<<endl;
}