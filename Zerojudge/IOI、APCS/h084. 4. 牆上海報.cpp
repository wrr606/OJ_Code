//h084. 4. 牆上海報
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

int n,k;
vi board,poster;

bool check(int length){
    int board_idx=0,poster_idx=0;
    while(board_idx<n&&poster_idx<k){
        for(int i=0;i<poster[poster_idx];i++){
            if(board[board_idx+i]<length){
                board_idx+=i+1;
                break;
            }
            if(i==poster[poster_idx]-1){
                poster_idx++;
                board_idx+=i+1;
                break;
            }
        }
    }
    if(poster_idx==k)
        return 1;
    return 0;
}

int binary_search(){
    int l=0,r=1e9,mid;
    while(l<=r){
        mid=l+((r-l)>>1);
        if(check(mid)){
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    return r;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>k;
    board.assign(n,0),poster.assign(k,0);
    for(auto &i:board)
        cin>>i;
    for(auto &i:poster)
        cin>>i;
    vi temp=board;
    sort(all(temp));
    cout<<binary_search()<<endl;
}