//d223. 10137 - The Trip
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

bool cmp(int a,int b){
    return a>b;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    while(cin>>n&&n){
        vector<int> x;
        double temp;
        int avg=0,ans=0,mod;
        for(int i=0;i<n;i++){
            cin>>temp;
            temp+=0.001;
            temp*=100;
            x.push_back(temp);
            avg+=temp;
        }
        mod=avg%n;
        avg/=n;
        sort(all(x),cmp);
        for(int i=0;i<mod;i++){
            ans+=abs(x[i]-avg-1);
        }
        for(int i=mod;i<n;i++){
            ans+=abs(x[i]-avg);
        }
        cout<<"$"<<setprecision(2)<<fixed<<(double)ans/200.0<<endl;
    }
}