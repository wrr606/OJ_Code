//d449. 垃圾信件
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

const int N=10005;
int cnt,num[N];
unordered_set<int> subnum[N];

int f(int cur){
    if(cur==num[cur])
        return cur;
    subnum[num[cur]].erase(cur);
    num[cur]=f(num[cur]);
    subnum[num[cur]].insert(cur);
    return num[cur];
}

void merge(int a,int b){
    a=f(a),b=f(b);
    if(a!=b){
        num[b]=a;
        subnum[a].insert(b);
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m;
    while(cin>>n){
        cin>>m;
        for(int i=1;i<=n;i++)
            num[i]=i,subnum[i].clear();
        cnt=0;
        while(m--){
            int op;
            cin>>op;
            if(op==1){
                int a,b;
                cin>>a>>b;
                merge(a,b);
            }
            else{
                int a,root;
                cin>>a;
                if(a==num[a]){
                    if(!subnum[a].size())
                        continue;
                    int first=*subnum[a].begin();
                    num[first]=first;
                    subnum[a].erase(first);
                    for(const auto &i:subnum[a]){
                        num[i]=first;
                        subnum[first].insert(i);
                    }
                    subnum[a].clear();
                }
                else{
                    int root=f(a);
                    for(const auto &i:subnum[a]){
                        subnum[root].insert(i);
                        num[i]=root;
                    }
                    subnum[num[a]].erase(a);
                    subnum[a].clear();
                    num[a]=a;
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(num[i]==i)
                cnt++;
        }
        cout<<cnt<<endl;
    }
}