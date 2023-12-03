//d756. 10290 - {Sum+=i++} to Reach N
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

#define MAXN 30000005

bitset<MAXN> prime_bool;
vector<ll> prime;

//線性篩
void find_prime(){
    prime_bool.set();
    for(int i=2;i<MAXN;i++){
        if(prime_bool[i]){
            prime.push_back(i);
        }
        for(auto j:prime){
            if(j*i>=MAXN)
                break;
            prime_bool[j*i]=0;
            if(i%j==0)
                break;
        }
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    find_prime();
    ll n;
    while(cin>>n){
        
        if(!n)
            cout<<1<<endl;
        else{
            ll pointer=1,ans=1,s=sqrt(n<<1);
            bool zero=0;
            if(s*(s+1)==n<<1)
                zero=1;
            while(!(n&1))
                n>>=1;
            while(n!=1&&pointer<prime.size()&&n>=pointer*pointer){
                ll temp=1;
                while(n%prime[pointer]==0){
                    temp++;
                    n/=prime[pointer];
                    //printf("%d %d\n",prime[pointer],temp);
                }
                ans*=temp;
                pointer++;
            }
            if(n!=1)
                ans<<=1;
            if(zero)
                ans++;
            cout<<ans<<endl;
        }
    }
}