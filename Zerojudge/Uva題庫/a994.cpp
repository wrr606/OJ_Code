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

int num, pick, d[15];

template <typename T>
T __lcm(T a, T b){
    return a * b / __gcd(a, b);
}

int f(const ll LCM = 1, const int sign = 1, const int idx = 0){
    if(LCM > num)
        return 0;
    if(idx == pick) //end
        return num / (int)LCM * sign;
    return f(LCM, sign, idx + 1) + f(__lcm(LCM, (ll)d[idx]), -sign, idx + 1);
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    while(cin>>num>>pick){
        for(int i = 0; i < pick; i++)
            cin>>d[i];
        cout<<f()<<endl;
    }
}