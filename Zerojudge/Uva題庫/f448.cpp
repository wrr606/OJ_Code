//f448. 1316 - Supermarket
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

//include deadline and profit
map<int,multiset<int> > products;
vector<int> temp;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,profit,deadline,ans,d;
    while(cin>>n){
        ans=0,products.clear(),temp.clear(),d=0;
        for(int i=0;i<n;i++){
            cin>>profit>>deadline;
            products[deadline].insert(profit);
        }
        auto b=products.begin();
        if((*b).first>1)
            d=(*b).first-1;
        for(auto it=products.rbegin();it!=products.rend();it++){
            for(auto j:temp){
                products[(*it).first].insert(j);
            }
            ans+=*(products[(*it).first].rbegin());
            products[(*it).first].erase(products[(*it).first].find(*(products[(*it).first].rbegin())));
            temp.clear();
            for(auto j:products[(*it).first])
                temp.emplace_back(j);
        }
        while(d--){
            auto a=products.begin();
            ans+=*(products[(*a).first].rbegin());
            products[(*a).first].erase(products[(*a).first].find(*(products[(*a).first].rbegin())));
        }
        cout<<ans<<endl;
    }
}
/*60+29+40+16+34+12
10  12 3    16 5     18 2    60 2   12 9    34 7    50 2    40 4    28 4    29 3              241
7   20 1    2 1     10 3    100 2   8 2     5 20    50 10               185
*/