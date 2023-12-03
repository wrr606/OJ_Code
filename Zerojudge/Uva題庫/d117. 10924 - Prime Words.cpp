#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

set<int> prime{1,2,3};

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    bool b=0;
    for(int i=5;i<=2000;i++){
        b=0;
        for(int j=2;j<=sqrt(i);j+=(j==2)?1:2)
            if(i%j==0){
                b=1;
                break;
            }
        if(!b)
            prime.insert(i);
    }
    string s;
    int counter=0;
    while(cin>>s){
        counter=0;
        for(auto i:s){
            if(i<='Z'&&'A'<=i)
                counter+=i-'A'+27;
            else
                counter+=i-'a'+1;
        }
        auto inter=prime.find(counter);
        //cout<<counter<<endl;
        if(inter!=prime.end())
            cout<<"It is a prime word.\n";
        else
            cout<<"It is not a prime word.\n";
    }
}