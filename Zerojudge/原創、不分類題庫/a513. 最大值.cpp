//a513. 最大值
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
    for(int c=1;c<=t;c++){
        int n,m;
        cin>>n>>m;
        priority_queue<int> pq;
        while(n--){
            int a;
            cin>>a;
            pq.push(a);
        }
        cout<<"Case "<<c<<":\n";
        while(m--){
            int op;
            cin>>op;
            if(op==1){
                int a;
                cin>>a;
                pq.push(a);
            }
            else{
                if(pq.empty())
                    cout<<"It's empty!\n";
                else{
                    cout<<"Max: "<<pq.top()<<endl;
                    pq.pop();
                }
            }
        }
        if(pq.empty()){
            cout<<"It's empty!\n";
            continue;
        }
        while(!pq.empty()){
            cout<<pq.top()<<" ";
            pq.pop();
        }
        cout<<endl;
    }
}