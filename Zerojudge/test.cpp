#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

#define mann 100

bitset<mann> isprime;
vector<int> prime;

void primes(){
    isprime.set(),prime.clear();
    isprime[0]=0,isprime[1]=0;
    for(int i=2;i<mann;i++){
        if(isprime[i])
            prime.push_back(i);
        for(auto j:prime){
            if(i*j>=mann)
                break;
            isprime[i*j]=0;
            if(i%j==0)
                break;
        }
    }
}

int main(){
    primes();
    for(int i=0;i<mann;i++){
        cout<<i<<" "<<isprime[i]<<"\n";
    }
}