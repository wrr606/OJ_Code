//k863. 清朝年號轉換
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
    map<string,int>year={{"ShunZhi", 1644} ,{"KangXi", 1662} ,{"YongZheng", 1723} ,{"QianLong", 1736} ,{"JiaQing", 1796} ,{"DaoGuang", 1821} ,{"XianFeng", 1851} ,{"TongZhi", 1862} ,{"GuangXu", 1875} ,{"XuanTong", 1909}};
    string s;
    int n;
    cin>>s>>n;
    cout<<year[s]+n-1;
}