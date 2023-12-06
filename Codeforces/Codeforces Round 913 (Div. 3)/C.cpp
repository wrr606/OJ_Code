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
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vector<int> > vvi;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        string s;
        cin>>n>>s;
        unordered_map<char,int> cnt;
        for(const auto &i:s)
            cnt[i]++;
        priority_queue<pair<int,char>> pq;
        for(const auto &i:cnt)
            pq.push({i.second,i.first});
        while(pq.size()>1&&pq.top().first!=0){
            auto fir=pq.top();
            pq.pop();
            auto sec=pq.top();
            pq.pop();
            if(fir.first-sec.first>0)
                pq.push({fir.first-sec.first,fir.second});
            else{
                pq.push({fir.first-1,fir.second});
                pq.push({sec.first-1,sec.second});
            }
        }
        cout<<pq.top().first<<endl;
    }
}