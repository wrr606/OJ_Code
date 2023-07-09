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
    int t;
    scanf("%d",&t);
    while(t--){
        double n,d,h;
        cin>>n>>d>>h;
        vector<int> num(n);
        for(auto &i:num)
            cin>>i;
        int last=num.front();
        double ans=d*h;
        for(int i=1;i<n;i++){
            if(num[i]-last>=h)
                ans+=d*h;
            else{
                ans+=d*h;
                ans-=(d*h)*(h-num[i]+last+0.0)/h*(h-num[i]+last+0.0)/h;
            }
            last=num[i];
        }
        ans/=2.0;
        cout<<setprecision(25)<<ans<<endl;
    }
}