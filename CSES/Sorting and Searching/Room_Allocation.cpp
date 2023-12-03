//Room_Allocation
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
typedef tree<int,null_type,less_equal<int>,rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

struct pii_index{
    int first,second,index;
};

bool cmp(pii_index a,pii_index b){
    if(a.first==b.first)
        return a.second<b.second;
    return a.first<b.first;
}


int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    vector<pii_index> person(n);
    vi ans(n);
    for(int i=0;i<n;i++)
        cin>>person[i].first>>person[i].second,person[i].index=i;
    sort(all(person),cmp);
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    int room=0;
    for(int i=0;i<n;i++){
        if(pq.empty()||pq.top().first>=person[i].first){
            room++;
            pq.push({person[i].second,room});
            ans[person[i].index]=room;
        }
        else{
            pii temp=pq.top();
            pq.pop();
            ans[person[i].index]=temp.second;
            pq.push({person[i].second,temp.second});
        }
    }
    cout<<room<<endl;
    for(const auto &i:ans)
        cout<<i<<" ";
}