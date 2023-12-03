//k733. 3. 磁軌移動序列
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    ll ans=0,x=10,mul=1;
    string s;
    vector<pair<int,ll> > stk;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]=='L'){
            int frequency=int(s[i+1])-48;
            stk.push_back({-1,frequency});
            i++;
        }
        else if(s[i]=='T'){
            int now=stoi(s.substr(i+1,2));
            ans+=abs(x-now)*mul;
            vector<pair<int,ll> > temp;
            while(!stk.empty()&&stk.back().first==-1){
                mul*=stk.back().second;
                temp.push_back(stk.back());
                stk.pop_back();
            }
            reverse(all(temp));
            for(auto j:temp){
                stk.push_back({now,j.second});
            }
            x=now;
            i+=2;
        }
        else if(s[i]=='E'){
            mul/=stk.back().second;
            ans+=abs(stk.back().first-x)*(stk.back().second-1)*mul;
            stk.pop_back();
        }
    }
    cout<<ans<<endl;
}