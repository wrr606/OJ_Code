//Collecting_Numbers_II
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

int check(vi &num,int a,int b){
    int res=0;
    if(num[a]<num[a-1])
        res++;
    if(num[a]>num[a+1])
        res++;
    if(num[b]<num[b-1])
        res++;
    if(num[b]>num[b+1])
        res++;
    if(a-b==1&&num[a]<num[b])
        res--;
    if(b-a==1&&num[a]>num[b])
        res--;
    return res;
}

int main(){////greedy 剪枝
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m,a,b,ans=1;
    cin>>n>>m;
    vi num(n+2),re_num(n+2);
    num[n+1]=INT_MAX;
    for(int i=1;i<=n;i++)
        cin>>a,num[a]=i,re_num[i]=a;
    for(int i=2;i<=n;i++){
        ans+=num[i]<num[i-1];
    }
    while(m--){
        cin>>a>>b;
        swap(re_num[a],re_num[b]);
        a=re_num[a],b=re_num[b];
        ans-=check(num,a,b);
        swap(num[a],num[b]);
        ans+=check(num,a,b);
        cout<<ans<<endl;
    }
}
/*
TLE GG
*/