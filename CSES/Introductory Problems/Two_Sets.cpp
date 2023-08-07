//Two_Sets
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
    set<int> a,b;
    int n;
    bool re=0;
    cin>>n;
    int sum_a=n,sum_b=0;
    a.insert(n);
    for(int i=n-1;i>0;i-=2){
        if(re)
            a.insert(i),(i-1>0)?(a.insert(i-1),sum_a+=2*i-1):sum_a+=i;
        else
            b.insert(i),(i-1>0)?(b.insert(i-1),sum_b+=2*i-1):sum_b+=i;
        re=!re;
    }
    if(sum_a==sum_b){
        cout<<"YES\n"<<a.size()<<endl;
        for(const auto &i:a)
            cout<<i<<" ";
        cout<<endl<<b.size()<<endl;
        for(const auto &i:b)
            cout<<i<<" ";
    }
    else
        cout<<"NO";
}