#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

bool cmp(int a,int b){
    return a>b;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll counter=0,a,b;
    cin>>a>>b;
    if(b>a)
        swap(a,b);
    while(b!=0){
        int temp=b;
        b=a%b;
        a=;
    }
    cout<<counter<<endl;
}