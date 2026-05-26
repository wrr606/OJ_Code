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

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;

    while (T--) {
        long long x, y, z, w, n, m;
        cin >> x >> y >> z >> w >> n >> m;

        string line;
        getline(cin, line);
        getline(cin, line);

        stringstream ss(line);
        int food;
        long long weight = m;
        long long poison = 0;
        bool alive = true;

        while (ss >> food) {
            weight -= poison * n;
            if (weight <= 0) {
                alive = false;
                break;
            }

            if (food == 1) {
                weight += x;
            } else if (food == 2) {
                weight += y;
            } else if (food == 3) {
                weight -= z;
            } else if (food == 4) {
                weight -= w;
                poison++;
            }

            if (weight <= 0) {
                alive = false;
                break;
            }
        }

        if (alive) {
            cout << weight << "g\n";
        } else {
            cout << "bye~Rabbit\n";
        }
    }

    return 0;
}