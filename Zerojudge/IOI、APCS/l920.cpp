//l920. P.3 建築倒塌 (Collapse)
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

bool check(const int &i,const int &n){
    return i>=0&&i<n;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    string s;
    int cnt=0;
    cin>>s;
    unordered_set<int> x_site;
    for(int i=0;i<s.size();i++){
        if(s[i]=='X'){
            x_site.insert(i);
            cnt++;
        }
    }
    int last=cnt+1;
    while(cnt>0&&cnt!=last){
        last=cnt;
        vector<pair<int,char>> cmd;
        for(const auto &i:x_site){
            bool l=0,r=0;
            if(check(i+1,s.size())&&s[i+1]=='L')
                l=1;
            if(check(i-1,s.size())&&s[i-1]=='R')
                r=1;
            if(l&&r)
                cmd.push_back({i,'X'});
            else if(l)
                cmd.push_back({i,'L'});
            else if(r)
                cmd.push_back({i,'R'});
        }
        for(const auto &i:cmd){
            if(i.second!='X'){
                x_site.erase(i.first);
                s[i.first]=i.second;
                cnt--;
            }
        }
    }
    cout<<s;
}