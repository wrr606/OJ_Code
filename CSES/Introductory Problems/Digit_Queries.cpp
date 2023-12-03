//Digit_Queries
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define all(x) x.begin(),x.end() 
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<ll> vll;


int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    ll num[30]={0,9},temp[30]={0,1};
    for(int i=2;i<29;i++){
        temp[i]=10*temp[i-1];
        num[i]=i*9*temp[i];
    }
    ll t,n;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<29;i++){
            if(n>num[i]){
                n-=num[i];
            }
            else{
                n--;
                ll div=n/i,mod=n%i;
                string s=to_string(temp[i]+div);
                cout<<s[mod]<<endl;
                break;
            }
        }
    }
}