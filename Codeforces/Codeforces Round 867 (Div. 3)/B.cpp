#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        ll n,temp;
        multiset<ll> x;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>temp;
            x.insert(temp);
        }
        ll max1=*(x.begin()),max2=*(++x.begin()),min1=*(x.rbegin()),min2=*(++x.rbegin());
        //cout<<max1<<"\t"<<max2<<"\t"<<min1<<"\t"<<min2<<"\n";
        if(max1*max2>min1*min2){
            cout<<max1*max2<<endl;
        }
        else{
            cout<<min1*min2<<endl;
        }
    }
}