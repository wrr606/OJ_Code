//d052. 11456 - Trainsorting
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

int main(){//LIS
    ios::sync_with_stdio(0),cin.tie(0);
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> trains(n),ans;
        for(auto &i:trains)
            cin>>i;
        trains.insert(trains.end(),all(trains));
        reverse(trains.begin(),trains.begin()+n);
        for(const auto &i:trains){
            if(ans.empty()||ans.back()<i){
                ans.push_back(i);
            }
            else{
                *lower_bound(all(ans),i)=i;
            }
        }
        cout<<ans.size()<<endl;
    }
}