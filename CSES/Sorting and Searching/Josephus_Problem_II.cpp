//Josephus_Problem_II
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

int main(){//約瑟夫問題
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m;
    cin>>n>>m;
    list<int> person;
    for(int i=1;i<=n;i++)
        person.push_back(i);
    auto iter=person.begin();
    while(n>0){
        n--;
        for(int i=0;i<m;i++){
            iter++;
            if(iter==person.end())
                iter=person.begin();
        }
        cout<<*iter<<" ";
        auto erase=iter;
        iter++;
        if(iter==person.end())
            iter=person.begin();
        person.erase(erase);
    }
}