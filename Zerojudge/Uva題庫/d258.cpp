#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

int main(){
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long int n,x,y,counter=0;
    cin>>n;
    while(n--){
        cin>>x>>y;
        counter=0;
        while(1){
            counter+=x/y;
            if(x==1){
                cout<<counter<<endl;
                break;
            }
            if(x<y){
                cout<<"cannot do this\n";
                break;
            }
            x=x/y+x%y;
        }
    }
}