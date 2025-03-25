//f416. 果然我的期中程設考搞錯了什麼
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

constexpr int N=1000005;
string a; // 文本串
string b; // 模板串(将被匹配的子串)
int kmp_next[N]; // next数组

void getNext(int m){//初始化
	int j = 0;
	kmp_next[0] = 0;
	for(int i=1; i<m; ++i){
		while(j>0 && b[i]!=b[j]) j=kmp_next[j-1];
		if(b[i]==b[j]) ++j;
		kmp_next[i] = j;
	}
}

int kmp(int n,int m){//使用KMP计算匹配次数
	int i, j = 0, res = 0;
	getNext(m);
	for(i=0; i<n; ++i){
		while(j>0 && b[j]!=a[i]) j=kmp_next[j-1];
		if(b[j]==a[i]) ++j;
		if(j==m) ++res;
	}
	return res;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t;
    cin>>t>>b>>a;
    getNext(b.size());
    if(t==kmp(a.size(),b.size()))
        cout<<"YES\n";
    else
        cout<<"NO\n";
}