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

struct cmp{
    bool operator()(const pii &a, const pii &b){
        if(a.first == b.first)
            return a.second < b.second;
        return a.first > b.first;
    }
};

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    priority_queue<pii, vector<pii>, cmp> pq;
    queue<pii> que;
    int t, q, x;
    cin>>t;
    for(int i = 0; i < t; i++){
        cin>>q;
        if(q == 1){
            cin>>x;
            que.emplace(x, i);
        }
        else if(q == 2){
            if(!pq.empty()){
                cout<<pq.top().first<<endl;
                pq.pop();
            }
            else{
                cout<<que.front().first<<endl;
                que.pop();
            }
        }
        else{
            while(!que.empty()){
                pq.emplace(move(que.front()));
                que.pop();
            }
        }
    }
}