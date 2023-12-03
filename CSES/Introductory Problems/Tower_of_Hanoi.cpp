//Tower_of_Hanoi
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

vector<pii > ans;

void recursion(int n,int a=1,int b=2,int c=3){
    if(n==1)
        ans.push_back({a,c});
    else{
        recursion(n-1,a,c,b);
        ans.push_back({a,c});
        recursion(n-1,b,a,c);
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    recursion(n);
    cout<<ans.size()<<endl;
    for(const auto &i:ans)
        cout<<i.first<<" "<<i.second<<endl;
}