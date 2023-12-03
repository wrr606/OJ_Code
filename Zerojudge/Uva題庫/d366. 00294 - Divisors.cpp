//d366. 00294 - Divisors
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

bool cmp(pii a,pii b){
    if(a.second==b.second)
        return a.first<b.first;
    else
        return a.second>b.second;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int max,min,t;
    cin>>t;
    for(int c=0;c<t;c++){
        cin>>min>>max;
        cout<<"Between "<<min<<" and "<<max<<", ";
        vector<pii> num;
        for(int i=min;i<=max;i++){
            int ans=1,temp=i;
            for(int j=2;j<=sqrt(i);j+=(j==2)?1:2){
                int counter=0;
                while(temp%j==0){
                    temp/=j;
                    counter++;
                }
                counter++;
                ans*=counter;
            }
            num.emplace_back(i,ans);
        }
        sort(all(num),cmp);
        cout<<num[0].first<<" has a maximum of "<<num[0].second<<" divisors.\n";
    }
}