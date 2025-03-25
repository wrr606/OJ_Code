#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int j,r,temp;
    while(cin>>j>>r&&j&&r){
        vector<int> x(j);
        for(int i=1;i<=r;i++)
            for(int k=0;k<j;k++){
                cin>>temp;
                x[k]+=temp;
            }
        int max=-1;
        for(int i=0;i<j;i++){
            if(x[i]>=max){
                max=x[i];
                temp=i;
            }
        }
        cout<<temp+1<<endl;
    }
}