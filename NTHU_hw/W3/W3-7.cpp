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

constexpr int MAXN = 1e6 + 5;

int Mynext[MAXN], Myprev[MAXN], que_number[MAXN], DSU[MAXN], head[MAXN], tail[MAXN];

int f(int cur){
    return DSU[cur]==cur?cur:DSU[cur]=f(DSU[cur]);
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n, m, cmd, a, b;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        head[i] = i;
        tail[i] = i;
        que_number[i] = i;
        DSU[i] = i;
    }
    while(m--){
        cin>>cmd>>a>>b;
        if(cmd == 0){
            const int query_a = f(que_number[a]);
            const int query_b = f(b);
            const int a_next = Mynext[a], a_prev = Myprev[a];
            if(a_next)
                Myprev[a_next] = a_prev;
            if(a_prev)
                Mynext[a_prev] = a_next;
            if(head[query_a] == a)
                head[query_a] = a_next;
            if(tail[query_a] == a)
                tail[query_a] = a_prev;
            Myprev[a] = tail[query_b];
            Mynext[a] = 0;
            
            if (head[query_b] == 0)
                head[query_b] = a;
            else
                Mynext[tail[query_b]] = a;
            tail[query_b] = a;
            que_number[a] = query_b;
        }
        else{
            const int query_a = f(a), query_b = f(b);
            if (query_a == query_b)
                continue;
            DSU[query_a] = query_b;
            if (head[query_a] != 0) {
                if (head[query_b] == 0) {
                    head[query_b] = head[query_a];
                    tail[query_b] = tail[query_a];
                } else {
                    Mynext[tail[query_b]] = head[query_a];
                    Myprev[head[query_a]] = tail[query_b];
                    tail[query_b] = tail[query_a];
                }
            }
            head[query_a] = 0;
            tail[query_a] = 0;
        }
    }
    for(int i=1;i<=n;i++){
        cout<<"#"<<i<<": ";
        int cur = head[i];
        while(cur != 0){
            cout<<cur<<" ";
            cur = Mynext[cur];
        }
        cout<<endl;
    }
}
/*
5 1
0 1 1

#1: 1
#2:
#3: 3 4
#4:
#5: 5 6 2
#6:
*/