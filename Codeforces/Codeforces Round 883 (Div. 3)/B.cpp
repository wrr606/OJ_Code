#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        bool draw=1;
        vector<string> s(3);
        for(auto &i:s)
            cin>>i;
        if(s[0][0]==s[0][1]&&s[0][1]==s[0][2]&&s[0][1]!='.'){
            cout<<s[0][0]<<endl;
            draw=0;
        }
        else if(s[1][0]==s[1][1]&&s[1][1]==s[1][2]&&s[1][1]!='.'){
            cout<<s[1][0]<<endl;
            draw=0;
        }
        else if(s[2][0]==s[2][1]&&s[2][1]==s[2][2]&&s[2][0]!='.'){
            cout<<s[2][0]<<endl;
            draw=0;
        }
        else if(s[0][0]==s[1][0]&&s[1][0]==s[2][0]&&s[0][0]!='.'){
            cout<<s[0][0]<<endl;
            draw=0;
        }
        else if(s[0][1]==s[1][1]&&s[1][1]==s[2][1]&&s[0][1]!='.'){
            cout<<s[0][1]<<endl;
            draw=0;
        }
        else if(s[0][2]==s[1][2]&&s[1][2]==s[2][2]&&s[0][2]!='.'){
            cout<<s[0][2]<<endl;
            draw=0;
        }
        else if(s[0][0]==s[1][1]&&s[1][1]==s[2][2]&&s[0][0]!='.'){
            cout<<s[0][0]<<endl;
            draw=0;
        }
        else if(s[0][2]==s[1][1]&&s[1][1]==s[2][0]&&s[0][2]!='.'){
            cout<<s[0][2]<<endl;
            draw=0;
        }
        if(draw)
            cout<<"DRAW\n";
    }
}