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
    int b1, g1, c1;
    int b2, g2, c2;
    int b3, g3, c3;

    while (cin>>b1>>g1>>c1>>b2>>g2>>c2>>b3>>g3>>c3){
        struct Option {
            string name;
            int moves;
        };

        vector<Option> options = {
            {"BCG", (b2 + b3) + (c1 + c3) + (g1 + g2)},
            {"BGC", (b2 + b3) + (g1 + g3) + (c1 + c2)},
            {"CBG", (c2 + c3) + (b1 + b3) + (g1 + g2)},
            {"CGB", (c2 + c3) + (g1 + g3) + (b1 + b2)},
            {"GBC", (g2 + g3) + (b1 + b3) + (c1 + c2)},
            {"GCB", (g2 + g3) + (c1 + c3) + (b1 + b2)}
        };

        int min_moves = INT_MAX;
        string best_config = "";

        for (const auto& opt : options){
            if (opt.moves < min_moves){
                min_moves = opt.moves;
                best_config = opt.name;
            }
        }

        cout<<best_config<<" "<<min_moves<<"\n";
    }
}