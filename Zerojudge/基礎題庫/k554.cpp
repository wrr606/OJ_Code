//k554. 地雷很危險
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

int n,m;

bool check(int i,int j){
    if(i<0||j<0||i>=n||j>=m)
        return 0;
    return 1;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int mp[105][105]={},bomb;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>bomb;
            if(bomb==1){
                mp[i][j]++;
                if(check(i+1,j)) mp[i+1][j]++;
                if(check(i,j+1)) mp[i][j+1]++;
                if(check(i-1,j)) mp[i-1][j]++;
                if(check(i,j-1)) mp[i][j-1]++;
            }
            else if(bomb==2){
                for(int k=0;k<n;k++)
                    if(check(k,j)) mp[k][j]++;
                for(int k=0;k<m;k++)
                    if(check(i,k)) mp[i][k]++;
                mp[i][j]--;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cout<<mp[i][j]<<" ";
        cout<<endl;
    }
}