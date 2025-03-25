//k516. P4.根號 (Sqrt)
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
    vector<vector<char> > star(n,vector<char>(n*5,' '));
    for(int i=0;i<n;i++)
        star[n/2][i]='*';
    int w=n,h=n/2+1;
    for(;w<n+(n+1)/2-2;w++,h++)
        star[h][w]='*';
    for(;h>=0;w++,h--)
        star[h][w]='*';
    for(int i=0;i<n*2-1;i++)
        star[0][w+i]='*';
    for(const auto &i:star){
        for(const auto &j:i)
            cout<<j;
        cout<<endl;
    }
}