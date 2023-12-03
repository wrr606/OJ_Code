//d285. 00727 - Postfix Expression
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    string s;
    int t;
    cin>>t;
    getline(cin,s);
    getline(cin,s);//輸入t後有一空行
    while(t--){
        vector<char> temp;
        string ans="";
        while(getline(cin,s)&&s!=""){
            auto i=s[0];
            if(i==' ')
                continue;
            if(i=='(')
                temp.push_back('(');
            else if(i==')'){
                while(!temp.empty()){
                    if(temp.back()=='('){
                        temp.pop_back();
                        break;
                    }
                    ans+=temp.back();
                    temp.pop_back();
                }
            }
            else if(i=='+'||i=='-'){
                while(!temp.empty()){
                    if(temp.back()!='+'&&temp.back()!='-'&&temp.back()!='*'&&temp.back()!='/')
                        break;
                    ans+=temp.back();
                    temp.pop_back();
                }
                temp.push_back(i);
            }
            else if(i=='*'||i=='/'){
                while(!temp.empty()){
                    if(temp.back()!='*'&&temp.back()!='/')
                        break;
                    ans+=temp.back();
                    temp.pop_back();
                }
                temp.push_back(i);
            }
            else{
                ans+=i;
            }
        }
        while(!temp.empty()){
            ans+=temp.back();
            temp.pop_back();
        }
        for(auto i:ans){
            cout<<i;
        }
        cout<<endl<<endl;
    }
}