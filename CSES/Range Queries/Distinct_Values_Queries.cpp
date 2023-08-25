//Distinct_Values_Queries
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

vll BIT;
int n;

bool cmp(array<int,4> a,array<int,4> b){
    return a[2]<b[2];
}

void update_add(int idx,int val){
    while(idx<=n){
        BIT[idx]+=val;
        idx+=(idx&-idx);
    }
}

ll query(int idx){
    ll res=0;
    while(idx>0){
        res+=BIT[idx];
        idx-=(idx&-idx);
    }
    return res;
}

int main(){//離線 BIT
    ios::sync_with_stdio(0),cin.tie(0);
    int q;
    cin>>n>>q;
    vi num(n+1);
    map<int,int> check;
    BIT.assign(n+1,0);
    for(int i=1;i<=n;i++)
        cin>>num[i];
    vector<array<int,4>> queries(q);
    for(int i=0;i<q;i++){
        cin>>queries[i][1]>>queries[i][2];
        queries[i][0]=i;
    }
    sort(all(queries),cmp);
    int cur=1;
    for(auto &i:queries){
        while(cur<=i[2]){
            if(check[num[cur]])
                update_add(check[num[cur]],-1);
            update_add(cur,1);
            check[num[cur]]=cur;
            cur++;
        }
        cur=i[2]+1;
        i[3]=query(i[2])-query(i[1]-1);
    }
    sort(all(queries));
    for(const auto &i:queries)
        cout<<i[3]<<endl;
}