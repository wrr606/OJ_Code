//d417. 10976 - Fractions Again?!
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

map<int,int> ans;

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int k;
    while(cin>>k){
        ans.clear();
        for(int i=1;i<=2*k;i++){
            if(i-k>0)
                if((k*i)%(i-k)==0)
                    ans[i]=k*i/(i-k);
        }
        cout<<ans.size()<<endl;
        for(auto i:ans){
            cout<<"1/"<<k<<" = 1/"<<i.second<<" + 1/"<<i.first<<endl;
        }
    }
}