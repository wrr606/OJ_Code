//Cyclic_Array
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
typedef vector<vector<int> > vvi;

#define MAX 200000000000000

vvi double_pointer(const vi &num,const int &n,const int &k){
    vvi dp1(n,vi(31));
    for(int l=0,r=0;l<n;l++){
        while(dp1[l][0]<=k){
            r%=n;
            dp1[l][0]+=num[r];
            r++;
        }
    }
    return dp1;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,k;
    ll sum=0;
    cin>>n>>k;
    vi num(n);
    for(auto &i:num){
        cin>>i;
        if(sum>MAX)
            sum=MAX+1;
        else
            sum+=i;
    }
    vvi dp1(double_pointer(num,n,k)),dp2;
    for(int i=1;i<32;i++){
        for(int j=0;j<n;j++){
            dp1[j][i]=dp1[dp1[j][i-1]][i-1];
            if(dp2[j][i-1]+dp2[dp1[j][i-1]][i-1]>sum)
                dp2[j][i]=dp2[j][i-1]+dp2[dp1[j][i-1]][i-1];
            else
                dp2[j][i]=sum;
        }
    }
    
}