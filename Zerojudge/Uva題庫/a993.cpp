//a993. 10127 - Ones
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,temp,counter;
    while(cin>>n){
        temp=1,counter=1;
        while(temp%n!=0){
            temp=(temp*10+1)%n;
            counter++;
        }
        cout<<counter<<endl;
    }
}