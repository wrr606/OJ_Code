//d396. 00524 - Prime Ring Problem
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

bitset<40> invited,isprime;
vector<int> prime;
int n,ans[40];

//線性質數篩
void primes(){
    isprime.set(),prime.clear();
    isprime[0]=0,isprime[1]=0;
    for(int i=2;i<40;i++){
        if(isprime[i])
            prime.push_back(i);
        for(auto j:prime){
            if(i*j>=40)
                break;
            isprime[i*j]=0;
            if(i%j==0)
                break;
        }
    }
}

void DFS(int cur){
    if(cur==n&&isprime[ans[0]+ans[n-1]]){
        for(int j=0;j<n;j++)
            cout<<ans[j]<<" ";
        cout<<endl;
    }
    else for(int i=2;i<=n;i++){
        if(!invited[i]&&isprime[i+ans[cur-1]]){
            ans[cur]=i;
            invited[i]=1;
            DFS(cur+1);
            invited[i]=0;
        }
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    primes();
    int c=1;
    while(cin>>n){
        ans[0]=1;
        cout<<"Case "<<c<<":\n";
        DFS(1);
        cout<<endl;
        c++;
    }
}