//f448. 1316 - Supermarket
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>

//include deadline and profit
vector<pii > products;
int n,profit,deadline,ans,day[10003];

bool cmp(pii a,pii b){
    return a.first>b.first;
}

int find(int x){
    return day[x]==-1?x:day[x]=find(day[x]);
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    while(cin>>n){
        products.clear(),ans=0,memset(day,-1,sizeof(day));
        for(int i=0;i<n;i++){
            cin>>profit>>deadline;
            products.push_back({profit,deadline});
        }
        sort(products.begin(),products.end(),cmp);
        for(int i=0;i<n;i++){
            int k=find(products[i].second);
            if(k){
                ans+=products[i].first;
                day[k]=k-1;
            }
        }
        cout<<ans<<endl;
    }
}
/*60+29+40+16+34+12
10  12 3    16 5     18 2    60 2   12 9    34 7    50 2    40 4    28 4    29 3              241
7   20 1    2 1     10 3    100 2   8 2     5 20    50 10               185
*/