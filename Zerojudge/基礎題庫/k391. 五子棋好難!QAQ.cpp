//k391. 五子棋好難!QAQ
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    string s1,s2;
    int i,j;
    cin>>s1>>i>>s2>>j;
    if(i==j){
        cout<<"tie\n";
    }
    else{
        map<int,string> member;
        member[i]=s1,member[j]=s2;
        cout<<member.rbegin()->second<<" WIN!\n";
    }
}