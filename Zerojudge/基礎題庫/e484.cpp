//e484. 我是優質學生
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

bool prime[10001];

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    memset(prime,1,sizeof(prime));
    prime[0]=0,prime[1]=0;
    int n;
    for(int i=2;i*i<=10000;i++)
        if(prime)
            for(int j=i+i;j<=10000;j+=i)
                prime[j]=0;
    cin>>n;
    if(prime[n])
        cout<<"yes\n";
    else
        cout<<"no\n";
}