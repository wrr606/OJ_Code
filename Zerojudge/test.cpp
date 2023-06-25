#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

int main(){
    vector<int> x{1,2,3,4,5,6};
    auto Max=max_element(x.begin(),x.end());

    cout<<*Max<<endl;

    

    for(auto i:x)
        cout<<i<<" ";
}