//Permutations
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
    int n;
    cin>>n;
    if(n<4&&n>1){
        cout<<"NO SOLUTION";
        return 0;
    }
    int temp=2;
    while(temp<=n){
        cout<<temp<<" ";
        temp+=2;
    }
    temp=1;
    while(temp<=n){
        cout<<temp<<" ";
        temp+=2;
    }
}