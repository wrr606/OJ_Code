//442 - Matrix Chain Multiplication
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
    int n;
    cin>>n;
    unordered_map<char,pii> matrix;
    for(int i=0;i<n;i++){
        char c;
        int a,b;
        cin>>c>>a>>b;
        matrix[c]={a,b};
    }
    string s;
    while(cin>>s){
        vector<pii> stk;
        bool error=0;
        int ans=0;
        for(const auto &i:s){
            if(i==')'){
                deque<pii> temp;
                while(!stk.empty()&&stk.back().first!='('){
                    temp.push_front(stk.back());
                    stk.pop_back();
                }
                stk.pop_back();
                pii cur;
                if(!temp.empty())
                    cur=temp[0];
                for(int i=1;i<temp.size();i++){
                    if(cur.second!=temp[i].first){
                        error=1;
                        cout<<"error\n";
                        break;
                    }
                    else{
                        ans+=cur.first*cur.second*temp[i].second;
                        cur={cur.first,temp[i].second};
                    }
                }
                if(!temp.empty())
                    stk.push_back(cur);
            }
            else if(i=='(')
                stk.push_back({'(','1'});
            else
                stk.push_back(matrix[i]);
            if(error)
                break;
        }
        if(error)
            continue;
        if(stk.size()>1){
            pii cur=stk[0];
            for(int i=1;i<stk.size();i++){
                if(cur.second!=stk[i].first){
                    error=1;
                    cout<<"error\n";
                    break;
                }
                else{
                    ans+=cur.first*cur.second*stk[i].second;
                    cur={cur.first,stk[i].second};
                }
            }
        }
        if(error)
            continue;
        cout<<ans<<endl;
    }
}