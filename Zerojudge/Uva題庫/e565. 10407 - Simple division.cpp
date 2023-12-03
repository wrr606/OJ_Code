//e565. 10407 - Simple division
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    vector<int> x;
    int temp1,temp2;
    while(cin>>temp1&&temp1){
        x.clear();
        while(cin>>temp2&&temp2){
            x.push_back(abs(temp1-temp2));
            temp1=temp2;
        }
        temp1=x[0];
        for(int i=1;i<x.size();i++){
            temp1=__gcd(temp1,x[i]);
        }
        cout<<temp1<<endl;
    }
}