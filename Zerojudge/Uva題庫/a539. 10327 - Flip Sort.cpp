#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,counter;
    while(cin>>n){
        counter=0;
        vector<int> x(n);
        for(int i=0;i<n;i++)
            cin>>x[i];
        for(int i=n-1;i>0;i--){
            for(int j=0;j<i;j++){
                if(x[j]>x[j+1]){
                    swap(x[j],x[j+1]);
                    counter++;
                }
            }
        }
        cout<<"Minimum exchange operations : "<<counter<<endl;
    }
}