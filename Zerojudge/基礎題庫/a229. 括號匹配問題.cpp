//a229. 括號匹配問題
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

int n,num;
string s;

void recursion(int cur=0,int l=0,int r=0){
    if(l>n||r>l)
        return;
    if(cur==num){
        cout<<s<<endl;
        return;
    }
    s[cur]='(';
    recursion(cur+1,l+1,r);
    s[cur]=')';
    recursion(cur+1,l,r+1);
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    while(cin>>n){
        num=n<<1;
        s.assign(' ',num);
        recursion();
        cout<<endl;
    }
}