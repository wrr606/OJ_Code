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
typedef vector<vector<int> > vvi;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
 
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,x;
    cin>>n>>x;
    vector<pii> num(n);
    for(int i=0;i<n;i++)
        cin>>num[i].first,num[i].second=i;
    sort(all(num));
    for(int i=0;i<n;i++){
        int l=0,r=n-1,mid,val=x-num[i].first;
        while(l<=r){
            mid=num[r].first+num[l].first;
            if(l!=i && l!=r && r!=i && mid==val){
                cout<<num[i].second+1<<" "<<num[l].second+1<<" "<<num[r].second+1<<endl;
                return 0;
            }
            else if(mid>val)
                r--;
            else
                l++;
        }
    }
    cout<<"IMPOSSIBLE\n";
}