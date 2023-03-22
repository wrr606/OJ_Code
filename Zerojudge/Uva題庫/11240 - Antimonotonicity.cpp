//11240 - Antimonotonicity
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> x(n);
        for(int i=0;i<n;i++){
            cin>>x[i];
        }
        int counter=1;
        for(int i=1;i<n;i++){
            if(counter%2&&x[i-1]>x[i]){
                counter++;
            }
            else if(!(counter%2)&&x[i-1]<x[i]){
                counter++;
            }
            //cout<<counter<<endl;
        }
        cout<<counter<<endl;
    }
}
/*
4
5 1 2 3 4 5
5 5 4 3 2 1
5 5 1 4 2 3
5 2 4 1 3 5

1
2
5
3
*/