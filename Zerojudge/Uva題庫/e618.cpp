//e618. 00484 - The Department of Redundancy Department
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    unordered_map<int,int> frequency;
    vector<int> number;
    int n;
    while(cin>>n){
        if(frequency[n]==0)
            number.push_back(n);
        frequency[n]++;
    }
    for(const auto &i:number)
        cout<<i<<" "<<frequency[i]<<endl;
}