//a779. 1. Reversal of Field
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
    string s;
    while(getline(cin,s)){
        cout<<s<<endl;
        list<char> link(all(s));
        auto iter=link.begin();
        while(iter!=link.end()){
            if((*iter<='Z'&&*iter>='A')||(*iter<='z'&&*iter>='a')||(*iter<='9'&&*iter>='0'))
                *iter=tolower(*iter),iter++;
            else
                iter=link.erase(iter);
        }
        s.assign(all(link));
        bool b=0;
        for(int i=0;i<s.size()>>1;i++)
            if(s[i]!=s[s.size()-1-i]){
                cout<<"-- is not a palindrome\n";
                b=1;
                break;
            }
        if(!b)
            cout<<"-- is a palindrome\n";
    }
}