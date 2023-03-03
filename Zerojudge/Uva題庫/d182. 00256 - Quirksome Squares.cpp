#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

int x[9]={};

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    x[2]=99,x[4]=9999,x[6]=999999,x[8]=99999999;
    int n,temp,counter;
    string s;
    while(cin>>n){
        counter=0;
        while(1){
            //cout<<"counter:"<<counter<<endl;
            temp=counter*counter;
            if(temp>=pow(10,n))
                break;
            if((int)pow(temp/(int)pow(10,n/2)+temp%(int)pow(10,n/2),2)==temp)
                cout<<setfill('0')<<setw(n)<<temp<<endl;
            counter++;
        }
    }
}