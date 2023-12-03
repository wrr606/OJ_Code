#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

bool cmp(pii a,pii b){
    return a.second>b.second;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,sec;
        cin>>n>>sec;
        vector<int> time(n);
        vector<int> value(n);
        cin>>time[0];
        for(int i=1;i<n;i++){
            cin>>time[i];
            time[i]+=i;
        }
        for(int i=0;i<n;i++){
            cin>>value[i];
        }
        vector<pii > ans;
        for(int i=0;i<n;i++){
            if(time[i]<=sec){
                ans.push_back({i,value[i]});
            }
        }
        if(ans.empty()){
            cout<<-1<<endl;
            continue;
        }
        sort(all(ans),cmp);
        cout<<ans.begin()->first+1<<endl;
    }
}