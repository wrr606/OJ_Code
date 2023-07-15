//Chessboard_and_Queens
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

vector<string> limit(8);
vi point(8);
vector<vector<bool> > invited(3,vector<bool>(999999));
ll ans=0;

void recursion(int n=0){
    if(n==8){
        ans++;
    }
    else{
        for(int i=0;i<8;i++){
            if(!invited[0][i]&&!invited[1][n+i]&&!invited[2][n-i+8]&&limit[n][i]=='.'){
                point[n]=i;
                invited[0][i]=invited[1][n+i]=invited[2][n-i+8]=1;
                recursion(n+1);
                invited[0][i]=invited[1][n+i]=invited[2][n-i+8]=0;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    for(auto &i:limit)
        cin>>i;
    recursion();
    cout<<ans;
}