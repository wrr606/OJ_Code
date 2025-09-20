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

const int MAXN = 2000;

class team{
public:
    long long int sum = 0;
    int persons = 0, order, mx = -1;
    vi arr;

    bool operator<(const team& other)const{
        if(sum == other.sum){
            if(mx == other.mx){
                if(persons == other.persons)
                    return order < other.order;
                return persons > other.persons;
            }
            return mx > other.mx;
        }
        return sum > other.sum;
    }
};
team teams[MAXN];

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t, n, m, num;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            teams[i] = {};
            cin>>m;
            for(int j=0;j<m;j++){
                cin>>num;
                teams[i].sum += num;
                teams[i].arr.emplace_back(num);
                teams[i].mx = max(teams[i].mx, num);
            }
            teams[i].order = i;
            teams[i].persons = m;
        }
        sort(teams, teams + n);
        for(int i=0;i<n;i++){
            for(const auto &j:teams[i].arr)
                cout<<j<<" ";
            cout<<endl;
        }
    }
}