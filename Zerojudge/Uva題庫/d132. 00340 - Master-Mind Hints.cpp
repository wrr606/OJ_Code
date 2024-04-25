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
    int n,ans[1005],code[1005],cnt=1;
    while(cin>>n && n){
        cout<<"Game "<<cnt++<<":\n";
        map<int,int> mp;
        for(int i=0;i<n;i++)
            cin>>ans[i],++mp[ans[i]];
        while(1){
            map<int,int> temp=mp,nomatch;
            int A=0,B=0;
            for(int i=0;i<n;i++)
                cin>>code[i];
            if(count(code,code+n,0)==n)
                break;
            for(int i=0;i<n;i++){
                if(ans[i]==code[i])
                    A++,--temp[code[i]];
                else
                    ++nomatch[code[i]];
            }
            for(const auto &[i,j]:nomatch)
                B+=min(temp[i],j);
            cout<<"\t("<<A<<','<<B<<")\n";
        }
    }
}