#include <bits/stdc++.h>
using namespace std;

#define j 70

int main(){
    int n;
    long long int male[j]={},female[j]={};
    female[0]=1;
    for(int i=1;i<=j-1;i++){
        female[i]+=male[i-1]+1;
        male[i]=male[i-1]+female[i-1];
    }
    while(cin>>n&&n!=-1){
        cout<<male[n]<<" "<<male[n]+female[n]<<endl;
    }
}