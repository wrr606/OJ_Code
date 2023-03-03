#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    string s,temp;
    int count=0;
    getline(cin,s);
    for(auto i:s){
        if(i==' '){
            count++;
        }
        else{
            if(count%2){
                temp+=' ';
            }
            count=0;
            temp+=i;
        }
    }
    cout<<temp;
}