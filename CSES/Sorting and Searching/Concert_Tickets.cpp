//Concert_Tickets
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define all(x) x.begin(),x.end() 
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<ll> vll;

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m,temp;
    cin>>n>>m;
    multiset<int> item;
    for(int i=0;i<n;i++)
        cin>>temp,item.insert(temp);
    for(int i=0;i<m;i++){
        cin>>temp;
        if(item.empty()){
            cout<<-1<<endl;
            continue;
        }
        auto iter=item.upper_bound(temp);
        if(iter!=item.begin())
            iter--;
        if(*iter>temp)
            cout<<-1<<endl;
        else{
            cout<<*iter<<endl;
            item.erase(iter);
        }
    }
}