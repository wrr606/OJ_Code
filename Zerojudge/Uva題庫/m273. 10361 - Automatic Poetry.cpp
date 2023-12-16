//m273. 10361 - Automatic Poetry
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
    int t;
    cin>>t;
    string s,s2,s3,s4,s5;
    getline(cin,s);
    while(t--){
        getline(cin,s);
        vi a,b;
        for(int i=0;i<s.size();i++){
            if(s[i]=='<')
                a.push_back(i);
            else if(s[i]=='>')
                b.push_back(i);
        }
        s2=s.substr(a[0]+1,b[0]-a[0]-1),s3=s.substr(b[0]+1,a[1]-b[0]-1);
        s4=s.substr(a[1]+1,b[1]-a[1]-1),s5=s.substr(b[1]+1);
        s.erase(b[1],1),s.erase(a[1],1),s.erase(b[0],1),s.erase(a[0],1);
        cout<<s<<endl;
        getline(cin,s);
        s.erase(s.size()-3);
        s+=s4,s+=s3,s+=s2,s+=s5;
        cout<<s<<endl;
    }
}