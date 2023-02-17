#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    map<int,string> dict={{1,"Pen"},{2,"Pineapple"},{3,"Apple"},{4,"Pineapple pen"}};
    vector<int> x;
    int n;
    cin>>n;
    for(int i=1;i<=70;i++){
        for(int j=1;j<=i;j++)
            x.push_back(1);
        for(int j=1;j<=i;j++)
            x.push_back(2);
        for(int j=1;j<=i;j++)
            x.push_back(3);
        for(int j=1;j<=i;j++)
            x.push_back(4);
    }
    cout<<dict[x[n-1]];
}