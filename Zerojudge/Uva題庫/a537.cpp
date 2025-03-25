#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

set<int> prime_number;
map<char,int> dict;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    bool b=0;
    prime_number.insert(2);
    for(int i=3;i<=2001;i++){
        b=0;
        for(int j=2;j<=sqrt(i);j+=(j==2)?1:2){
            if(i%j==0)
                b=1;
        }
        if(!b)
            prime_number.insert(i);
    }
    int n;
    string s;
    cin>>n;
    for(int counter=1;counter<=n;counter++){
        b=1;
        dict.clear();
        cin>>s;
        cout<<"Case "<<counter<<": ";
        for(int i=0;i<s.size();i++){
            dict[s[i]]++;
        }
        for(auto i:dict){
            auto j=prime_number.find(i.second);
            if(j!=prime_number.end()){
                cout<<i.first;
                b=0;
            }
        }
        if(b)
            cout<<"empty\n";
        else
            cout<<endl;
    }
}