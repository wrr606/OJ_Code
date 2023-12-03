//1605 Building for UN
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

char eng[52];

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    for(int i=0;i<26;i++)
        eng[i]='a'+i;
    for(int i=0;i<26;i++)
        eng[i+26]='A'+i;
    int n;
    while(cin>>n){
        string s="";
        cout<<2<<" "<<n<<" "<<n<<endl;
        for(int i=0;i<n;i++){
            s+=eng[i];
        }
        for(int i=0;i<n;i++)
            cout<<s<<endl;
        cout<<endl;
        for(const auto &i:s){
            for(int j=0;j<n;j++){
                cout<<i;
            }
            cout<<endl;
        }
    }
}