#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

int main(){
    //ios::sync_with_stdio(0),cin.tie(0);
    vector<int> x;
    x.push_back(1);
    x.push_back(2);
    x.push_back(3);
    while(!x.empty()&&x.back()!=0){
        cout<<x.back()<<endl;
        x.pop_back();
    }
    cout<<"complete"<<endl;
}