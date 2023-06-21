#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

int main(){
    map<int,int> x;
    x[1]++;
    x[2]++;
    x[3]++;
    x[4]++;
    auto iter=x.rbegin();
    iter++;
    cout<<(*iter).first<<endl;
}