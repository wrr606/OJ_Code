//e569. 00245 - Uncompress
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

vector<string> word;

void vector_find_and_erase(string x){
    for(int i=0;i<word.size()-1;i++){
        if(word[i]==x){
            word.erase(word.begin()+i);
            break;
        }
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    string s,text,w;
    int counter=0;
    bool num=0;
    while(getline(cin,s)&&s!="0"){
        s+='\n';
        text+=s;
    }
    for(int i=0;i<text.size();i++){
        if(isalpha(text[i])){
            w+=text[i];
        }
        else if(text[i]>=48&&text[i]<=57){
            counter=counter*10+int(text[i])-48;
            num=1;
            continue;
        }
        else if(num){
            num=0;
            auto it=word.rbegin()+(counter-1);
            string temp=*it;
            word.push_back(temp);
            vector_find_and_erase(temp);
            cout<<temp<<text[i];
            counter=0;
            continue;
        }
        else if(w!=""){
            word.push_back(w);
            w="";
        }
        cout<<text[i];
    }
}