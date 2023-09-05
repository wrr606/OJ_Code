//a146. Sliding Window
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

const int N=1e6+5;
int num[N];

int main(){//單調隊列
    ios::sync_with_stdio(0),cin.tie(0);
    int n,window;
    while(cin>>n){
        cin>>window;
        window=min(n,window);
        vi ans_max,ans_min;
        for(int i=0;i<n;i++)
            cin>>num[i];
        deque<int> mx,mn;
        for(int i=0;i<n;i++){
            if(!mx.empty()&&i-mx.front()>=window)
                mx.pop_front();
            if(!mn.empty()&&i-mn.front()>=window)
                mn.pop_front();
            while(!mx.empty()&&num[mx.back()]<num[i])
                mx.pop_back();
            while(!mn.empty()&&num[mn.back()]>num[i])
                mn.pop_back();
            mx.push_back(i),mn.push_back(i);
            if(i>=window-1){
                ans_max.push_back(num[mx.front()]);
                ans_min.push_back(num[mn.front()]);
            }
        }
        for(int i=0;i<ans_min.size()-1;i++)
            cout<<ans_min[i]<<" ";
        cout<<ans_min.back()<<endl;
        for(int i=0;i<ans_max.size()-1;i++)
            cout<<ans_max[i]<<" ";
        cout<<ans_max.back()<<endl;
    }
}