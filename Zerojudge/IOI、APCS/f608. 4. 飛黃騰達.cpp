//f608. 4. 飛黃騰達
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

int main(){//LIS
    ios::sync_with_stdio(0),cin.tie(0);
    int n,x,y;
    cin>>n;
    vector<pii> coordinate(n);
    for(auto &i:coordinate)
        cin>>i.first>>i.second;
    sort(all(coordinate));
    vector<int> ans;
    for(const auto &i:coordinate){
        if(ans.empty()||ans.back()<=i.second)
            ans.push_back(i.second);
        else
            *upper_bound(all(ans),i.second)=i.second;
    }
    cout<<ans.size()<<endl;
}