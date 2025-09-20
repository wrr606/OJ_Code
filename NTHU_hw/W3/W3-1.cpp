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

struct person{
    long long int x, y;
    bool dir;
};

constexpr long long int MAXN = 1e6 * 2 + 5;
pair<long long int, bool> arr[MAXN];
person a = {0, 0, 1}, b = {0, 0, 0};
long long int k, meets = 0, x = 0, y = 0;

inline void check(const person a_future, const person b_future){
    if(a.dir == b.dir){
        if(a.x!=b.x || a.y!=b.y)
            return;
        meets += abs(a.x - a_future.x) + abs(b.y - b_future.y);
    }
    else{
        if((a.x < b.x && b.x <= a_future.x) && (b.y < a.y && a.y <= b_future.y))
            meets++;
        else if((b.x < a.x && a.x <= b_future.x) && (a.y < b.y && b.y <= a_future.y))
            meets++;
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n, m;
    cin>>k>>n>>m;
    for(int i=0;i<n;i++)
        cin>>arr[i].first, --arr[i].first, arr[i].second=0;
    for(int i=n;i<n+m;i++)
        cin>>arr[i].first, --arr[i].first, arr[i].second=1;
    sort(arr, arr+n+m), x = k, y = k;//init
    for(int i=0;i<n+m;i++){
        const auto &[now, t] = arr[i];
        if(!t){//a
            const person a_future = {a.x + (!a.dir ? now - a.x - a.y : 0), a.y + (a.dir ? now - a.x - a.y : 0), !a.dir},
                         b_future = {b.x + (!b.dir ? now - b.x - b.y : 0), b.y + (b.dir ? now - b.x - b.y : 0), b.dir};
            check(a_future, b_future);
            a = a_future, b = b_future;
        }
        else{//b
            const person a_future = {a.x + (!a.dir ? now - a.x - a.y : 0), a.y + (a.dir ? now - a.x - a.y : 0), a.dir},
                         b_future = {b.x + (!b.dir ? now - b.x - b.y : 0), b.y + (b.dir ? now - b.x - b.y : 0), !b.dir};
            check(a_future, b_future);
            a = a_future, b = b_future;
        }
        // cout<<now<<" "<<t<<endl;
        // cout<<a.x<<" "<<a.y<<"\t"<<b.x<<" "<<b.y<<"\t"<<meets<<endl<<endl;
    }
    const person a_future = {a.x + (!a.dir ? k - a.x - a.y : 0), a.y + (a.dir ? k - a.x - a.y : 0), a.dir},
                 b_future = {b.x + (!b.dir ? k - b.x - b.y : 0), b.y + (b.dir ? k - b.x - b.y : 0), b.dir};
    check(a_future, b_future);
    cout<<x-meets<<" "<<y-meets<<" "<<meets;
}
/*
15 4 4
4 8 12 13
3 8 10 14

0 4
3 0

-
4 4
3 5
  -
*/