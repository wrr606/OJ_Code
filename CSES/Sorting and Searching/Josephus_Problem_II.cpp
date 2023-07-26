//Josephus_Problem_II
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define all(x) x.begin(),x.end() 
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int> > vvi;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main(){//約瑟夫問題 pbds
    ios::sync_with_stdio(0),cin.tie(0);
    ordered_set person;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        person.insert(i);
    int index=m%n,num=n;
    while(num--){
        auto now=person.find_by_order(index);
        cout<<*now<<" ";
        person.erase(now);
        if(num)
            index=(index+m)%num;
    }
}