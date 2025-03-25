#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t,counter=0;
    cin>>t;
    vector<string> x(t),y(t);
    string ans[110]={},question;
    for(int i=0;i<t;i++){
        cin>>x[i]>>y[i];
    }
    cin>>question;
    for(int i=0;i<t;i++){
        if(x[i]==question){
            ans[counter]=y[i];
            counter++;
        }
        else if(y[i]==question){
            ans[counter]=x[i];
            counter++;
        }
    }
    if(counter)
        sort(ans,ans+counter);
    else
        cout<<"No";
    for(int i=0;i<counter;i++)
        cout<<ans[i]<<endl;
}