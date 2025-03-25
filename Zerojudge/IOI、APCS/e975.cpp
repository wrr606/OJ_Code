//e975. 3. 情書解密 (Love)
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

char low(int c){
    if(c<97)
        return 122-96+c;
    if(c>122)
        return c-122+96;
    return c;
}

char high(int c){
    if(c<65)
        return 90-64+c;
    if(c>90)
        return c-90+64;
    return c;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    string s,love="love",Love="Love";
    getline(cin,s);
    if(s.find(love)!=s.npos||s.find(Love)!=s.npos){
        cout<<0;
        return 0;
    }
    for(int i=1;i<26;i++){
        for(auto &j:love)
            j=low(--j);
        Love[0]=high(--Love[0]);
        for(int j=1;j<4;j++)
            Love[j]=low(--Love[j]);
        
        if(s.find(love)!=s.npos||s.find(Love)!=s.npos){
            cout<<i;
            return 0;
        }
    }
}