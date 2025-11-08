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
    int n, val;
    cin>>n;
    set<int> st;
    for(int i=0;i<n;i++)
        cin>>val, st.emplace(val);
    int q, op, x, k;
    cin>>q;
    while(q--){
        cin>>op;
        if(op == 1){
            cin>>x;
            st.emplace(x);
        }
        else{
            cin>>x>>k;
            auto l = st.lower_bound(x);//move r
            auto r = st.end();//move l
            if(l != st.begin())
                r = prev(l);
            bool l_check = (l != st.end()), 
                 r_check = (r != st.end());
            int l_dis, r_dis, k_val;
            for(int i=0;i<k;i++){
                if(l_check)
                    l_dis = abs(x - *l);
                if(r_check)
                    r_dis = abs(x - *r);
                // cout<<l_dis<<" "<<r_dis<<endl;
                if(l_check && (l_dis < r_dis || !r_check)){
                    k_val = *l;
                    l++;
                    if(l == st.end())
                        l_check = 0;
                }
                else{
                    k_val = *r;
                    if(r == st.begin())
                        r_check = 0;
                    else
                        r--;
                }
            }
            // for(auto i:st)
            //     cout<<i<<" ";cout<<endl;
            cout<<k_val<<endl;
            st.erase(k_val);
        }
    }
}