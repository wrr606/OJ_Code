//h075. 成績排名
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
    int num,information,math,english,avg;
};

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    student students[101];
    cin>>n;
    for(int i=0;i<n;i++){
        int num,information,math,english;
        cin>>num>>information>>math>>english;
        students[i]={num,information,math,english,information*5+math*3+english*2};
    }
    sort(students,students+n,[](student a,student b){
        if(a.avg==b.avg){
            if(a.information==b.information){
                if(a.math==b.math){
                    if(a.english==b.english)
                        return a.num<b.num;
                    return a.english>b.english;
                }
                return a.math>b.math;
            }
            return a.information>b.information;
        }
        return a.avg>b.avg;
    });
    for(int i=0;i<n;i++)
        cout<<students[i].num<<" "<<students[i].avg/10.0<<endl;
}