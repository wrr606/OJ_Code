//a007. 判斷質數
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

bitset<2147483648> prime;
vector<int> primes;

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    prime.set();
    prime[0]=0,prime[1]=0;
    ll n;
    //線性篩 O(n)
    for(int i=2;i*i<=2147483647;i++){
        if(prime[i])
            primes.push_back(i);
        for(auto j:primes){
            if(i*j>=2147483647)
                break;
            prime[i*j]=1;
            if(i%j==0)
                break;
        }
    }
    while(cin>>n){
        if(prime[n])
            cout<<"質數\n";
        else
            cout<<"非質數\n";
    }
}