//120 Stacks of Flapjacks
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

void splite(string &s,vector<int> &number){
    int temp=0;
    for(const auto &i:s){
        if(i!=' '){
            temp*=10;
            temp+=int(i)-48;
        }
        else{
            number.push_back(temp);
            temp=0;
        }
    }
    number.push_back(temp);
    cout<<s<<endl;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    string s;
    while(getline(cin,s)){
        vector<int> number;
        splite(s,number);
        for(int i=number.size()-1;i>=0;i--){
            //max_element return()的是迭代器
            auto Max=max_element(number.begin(),number.begin()+i+1);
            if(number[i]!=*Max){
                if(number[0]==*Max){
                    reverse(number.begin(),number.begin()+i+1);
                    cout<<number.size()-i<<" ";
                }
                else{
                    reverse(number.begin(),Max+1);
                    cout<<number.size()-(Max-number.begin())<<" ";
                    i++;
                }
            }
        }
        cout<<"0\n";
    }
}