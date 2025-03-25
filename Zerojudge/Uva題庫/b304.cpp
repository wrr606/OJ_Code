//b304. 00673 - Parentheses Balance
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    string s;
    getline(cin,s);
    while(n--){
        bool ans=1;
        getline(cin,s);
        if(s==""){
            cout<<"Yes\n";
            continue;
        }
        vector<char> parentheses;
        for(auto i:s){
            if(i=='('||i=='['){
                parentheses.push_back(i);
            }
            else{
                if(i==')'&&!parentheses.empty()){
                    if(parentheses.back()!='('){
                        parentheses.push_back(i);
                        break;
                    }
                    parentheses.pop_back();
                }
                else if(i==']'&&!parentheses.empty()){
                    if(parentheses.back()!='['){
                        parentheses.push_back(i);
                        break;
                    }
                    parentheses.pop_back();
                }
                else{
                    parentheses.push_back(i);
                    break;
                }
            }
        }
        if(parentheses.empty())
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
}