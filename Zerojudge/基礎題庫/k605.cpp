//k605. 班級成績單
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

struct student{
    int no;
    string name;
    vi grades;
    int sum=0;
};

bool cmp(student a,student b){
    if(a.sum==b.sum)
        return a.no<b.no;
    return a.sum>b.sum;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    vector<student> person(n);
    for(auto &i:person){
        cin>>i.no>>i.name;
        i.grades.assign(5,0);
        for(auto &j:i.grades)
            cin>>j,i.sum+=j;
    }
    sort(all(person),cmp);
    auto f=person[0];
    int rank=1,temp=f.sum;
    cout<<f.no<<" "<<f.name<<" ";
    for(const auto &i:f.grades)
        cout<<i<<" ";
    cout<<f.sum<<" "<<rank<<endl;
    for(int i=1;i<person.size();i++){
        auto cur=person[i];
        cout<<cur.no<<" "<<cur.name<<" ";
        for(const auto &j:cur.grades)
            cout<<j<<" ";
        cout<<cur.sum<<" ";
        if(temp!=cur.sum)
            rank=i+1,temp=cur.sum;
        cout<<rank<<endl;
    }
}