#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int h,w;
    string s;
    cin>>h>>w;
    for(int i=0;i<h;i++){
        cin>>s;
        for(int j=0;j<w-1;j++){
            if(s[j]=='T'&&s[j+1]=='T'){
                s[j]='P',s[j+1]='C';
            }
        }
        cout<<s<<endl;
    }
}