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

int n, b, d;
string a, c;
vi heap[25];
int pos[25];//  heap position

void init(){
    for(int i = 0; i < n; i++){
        pos[i] = i;
        heap[i] = {i};
    }
}

inline void update(const int n, const int idx){
    heap[idx].emplace_back(n);
    pos[n] = idx;
}

inline int get_pos(const int n){
    return pos[n];
}

vi MOVE(const int x){
    auto &cur_heap = heap[get_pos(x)];
    int last = -1;
    while(cur_heap.size() && last != x){
        last = cur_heap.back();
        cur_heap.pop_back();

        if(last != x)
            update(last, last);
    }
    return {x};
}

vi PILE(const int x){
    auto &cur_heap = heap[get_pos(x)];
    vi t;
    int last = -1;
    while(cur_heap.size() && last != x){
        last = cur_heap.back();
        cur_heap.pop_back();
        t.push_back(last);
    }
    reverse(all(t));
    return t;
}

void ONTO(const int y, const vi &t){
    auto &cur_heap = heap[get_pos(y)];
    int last = -1;
    while(cur_heap.size() && last != y){
        last = cur_heap.back();
        cur_heap.pop_back();

        if(last != y)
            update(last, last);
    }
    cur_heap.push_back(y);
    
    for(const auto &i: t)
        update(i, get_pos(y));
}

void OVER(const int y, const vi &t){
    for(const auto &i: t)
        update(i, get_pos(y));
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    
    while(cin>>n){
        init();

        while(cin>>a && a != "quit"){
            cin>>b>>c>>d;
            
            //except
            if(b == d || pos[b] == pos[d])
                continue;

            const vi t = ((a == "move") ? MOVE(b) : PILE(b));
            (c == "onto") ? ONTO(d, t) : OVER(d, t);
        }

        for(int i = 0; i < n; i++){
            cout<<i<<": ";
            for(const auto &j: heap[i])
                cout<<j<<" ";
            cout<<endl;
        }
    }
}