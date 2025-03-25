//i400. 2. 字串解碼
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

string decode(string s,string password){
    int count=0;
    string ans="",ans_return="";
    for(int i=s.size()-1;i>=0;i--){
        if(s[i]=='1'){
            count++;
            ans+=password[i];
        }
        else{
            ans.insert(ans.begin(),password[i]);
        }
    }
    if(count&1){
        if(ans.size()&1){
            ans_return+=ans.substr(ans.size()/2+1);
            ans_return+=ans[ans.size()/2];
            ans_return+=ans.substr(0,ans.size()/2);
        }
        else{
            ans_return+=ans.substr(ans.size()/2);
            ans_return+=ans.substr(0,ans.size()/2);
        }
        return ans_return;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int m,n;
    cin>>m>>n;
    string password;
    vector<string> s(m);
    for(auto &i:s)
        cin>>i;
    cin>>password;
    string temp=decode(s[m-1],password);
    for(int i=m-2;i>=0;i--){
        temp=decode(s[i],temp);
    }
    cout<<temp<<endl;
}