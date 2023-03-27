#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    vector<string> dream;
    string command,name;
    int n;
    cin>>n;
    while(n--){
        cin>>command;
        if(command=="Sleep"){
            cin>>name;
            dream.push_back(name);
        }
        else if(command=="Kick"){
            if(!dream.empty())
                dream.pop_back();
        }
        else{
            if(dream.empty()){
                cout<<"Not in a dream\n";
            }
            else{
                cout<<*(dream.rbegin())<<endl;
            }
        }
    }
}