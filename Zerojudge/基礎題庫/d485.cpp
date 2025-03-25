//d485. 我愛偶數
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int a,b;
    cin>>a>>b;
    cout<<abs(((b-a)+(a%2==0)+(b%2==0))/2)<<endl;
}