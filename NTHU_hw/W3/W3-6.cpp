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

constexpr int MAXN = 10000 + 1;

unordered_map<string,int> positions_order = {
    {"elder", 1},
    {"nursy", 2},
    {"kit", 3},
    {"warrior", 4},
    {"appentice", 5},
    {"medicent", 6},
    {"deputy", 7},
    {"leader", 8}
};

bool string_cmp(string_view a, string_view b){
    for(int i=0;i<min(a.size(), b.size());i++){
        if(a[i] != b[i])
            return a[i] < b[i];
    }
    return a.size() < b.size();
}

class cat{
public:
    string name, position;
    int age;

    bool operator<(const cat& other)const{
        if(position == other.position){
            if(position == "appentice"){
                if(age == other.age)
                    return string_cmp(name, other.name);
                return age < other.age;
            }
            else{
                if(age == other.age)
                    return string_cmp(name, other.name);
                return age > other.age;
            }
        }
        return positions_order[position] < positions_order[other.position];
    }
};
cat cats[MAXN];

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n, m;
    while(cin>>n>>m){
        for(int i=0;i<n;i++)
            cin>>cats[i].name>>cats[i].position>>cats[i].age;
        sort(cats, cats + n);
        for(int i=0;i<m && i<n;i++)
            cout<<cats[i].name<<endl;
    }
}