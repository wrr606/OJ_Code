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

inline bool check(const vs &x){
    const int n=x.size();
    pii f={0,0},t={0,0};
    int index;
    bool find=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(x[i][j]=='1'){
                if(find==0)
                    f.first=j,index=i;
                f.second++;
                find=1;
            }
        }
        if(find)
            break;
    }
    find=0;
    for(int j=0;j<n;j++){
        if(x[index+1][j]=='1'){
            if(find==0)
                t.first=j;
            t.second++;
            find=1;
        }
    }
    if(f==t)
        return 1;
    return 0;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vs s(n);
        for(auto &i:s)
            cin>>i;
        if(check(s))
            cout<<"SQUARE\n";
        else
            cout<<"TRIANGLE\n";
    }
}