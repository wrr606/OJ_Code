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

vi x(1e6);

void bs(){
    int l=0,r=1e6,mid;
    while(l<r){
        mid=l+(r-l)/2;
        if(mid<16)
            l=mid+1;
        else
            r=mid;
    }
    cout<<l<<" "<<mid<<" "<<r<<endl;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    for(int i=0;i<1e6;i++)
        x[i]=i;
    bs();
}