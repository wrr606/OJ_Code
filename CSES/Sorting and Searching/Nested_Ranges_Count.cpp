//Nested_Ranges_Count
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

struct range_and_index{
    int first,second,index;
};

bool cmp(range_and_index a,range_and_index b){
    if(a.first==b.first)
        return a.second>b.second;
    return a.first<b.first;
}

int main(){//greedy sort pbds
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    vector<range_and_index> range(n);
    vi contains(n),contained(n);
    for(int i=0;i<n;i++)
        cin>>range[i].first>>range[i].second,range[i].index=i;
    sort(all(range),cmp);
    ordered_multiset record,record_reverse;
    for(int i=0;i<n;i++){
        record.insert(range[i].second);
        contained[range[i].index]=record.size()-record.order_of_key(range[i].second)-1;
    }
    for(int i=n-1;i>=0;i--){
        contains[range[i].index]=record_reverse.order_of_key(range[i].second+1);
        record_reverse.insert(range[i].second);
    }
    for(const auto &i:contains)
        cout<<i<<" ";
    cout<<endl;
    for(const auto &i:contained)
        cout<<i<<" ";
}