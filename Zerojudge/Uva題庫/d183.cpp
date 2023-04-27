//d183. 00725 - Division
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

multimap<int,int> dict;

string del(string s,char c){
    for(int i=0;i<s.size();i++){
        if(s[i]==c){
            s.erase(i,1);
            return s;
        }
    }
    return s;
}

void brute_recursion2(string s,string x,string old){
    if(s.size()==5){
        dict.insert({stoi(old),stoi(s)});
    }
    else{
        for(auto i:x){
            string temp=s;
            temp+=i;
            brute_recursion2(temp,del(x,i),old);
        }
    }
}

void brute_recursion1(string s="",string x="0123456789"){
    if(s.size()==5){
        brute_recursion2("",x,s);
    }
    else{
        for(auto i:x){
            string temp=s;
            temp+=i;
            brute_recursion1(temp,del(x,i));
        }
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    brute_recursion1();
    cout<<dict.size()<<endl;
    int s;
    while(cin>>s&&s){
        bool b=0;
        for(auto i:dict){
            //cout<<i.first<<" "<<i.second<<" "<<s<<endl;
            if(i.first==i.second*s){
                cout<<i.first<<" / "<<i.second<<" = "<<s<<endl;
                b=1;
            }
        }
        if(!b)
            cout<<"There are no solutions for "<<s<<".\n";
    }
}