//714 - Copying Books
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<ll,ll>
#define all(x) x.begin(),x.end() 
#define ll long long

ll n,m;
vector<ll> book;

bool check(ll num){
    ll Max=0,work=0;
    for(const auto &i:book){
        Max+=i;
        if(Max>num){
            Max=i;
            work++;
        }
    }
    return work<m;
}

ll binary_search(ll l,ll r){
    ll mid;
    while(r>l){
        mid=l+r>>1;
        if(check(mid))
            r=mid;
        else
            l=mid+1;
    }
    return l;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    ll t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        book.assign(n,0);
        ll Max=0,sum=0;
        for(auto &i:book){
            cin>>i;
            Max=max(Max,i);
            sum+=i;
        }
        Max=binary_search(Max,sum);
        vector<vector<ll> > ans(m);
        vector<ll> ans_check(m,Max);
        ll index=m-1;

        for(ll i=n-1;i>=0;i--){//greedy algorithm
            if(i<index)
                index--,i++;
            else if(ans_check[index]>=book[i]){
                ans_check[index]-=book[i];
                ans[index].push_back(book[i]);
            }
            else
                index--,i++;
        }

        for(ll i=0;i<m-1;i++){//嚴格輸出...
            for(ll j=ans[i].size()-1;j>=0;j--){
                cout<<ans[i][j]<<" ";
            }
            cout<<"/ ";
        }
        for(ll i=ans.back().size()-1;i>0;i--)
            cout<<ans.back()[i]<<" ";
        cout<<ans.back().front()<<endl;
    }
}