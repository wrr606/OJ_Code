//c276. 沒有手機的下課時間
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    string s,x;
    cin>>s;
    int n;
    cin>>n;
    while(n--){
        cin>>x;
        int a=0,b=0;
        for(int i=0;i<4;i++){
            if(s[i]==x[i]){
                a++;
                x[i]='X';
            }
        }
        for(const auto &i:x){
            if(s.find(i)!=-1)
                b++;
        }
        cout<<a<<"A"<<b<<"B\n";
    }
}