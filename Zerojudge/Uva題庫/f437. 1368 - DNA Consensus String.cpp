#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t,m,n;
    map<char,int> dict;
    cin>>t;
    while(t--){
        int counter=0;
        string ans="";
        cin>>m>>n;
        vector<string> s(m);
        for(int i=0;i<m;i++){
            cin>>s[i];
        }
        for(int i=0;i<n;i++){
            dict.clear();
            for(int j=0;j<m;j++){
                dict[s[j][i]]++;
            }
            int max_int=-1;
            char max_char='\0';
            for(auto j:dict){
                if(j.second>max_int){
                    max_char=j.first;
                    max_int=j.second;
                }
            }
            ans+=max_char;
            counter+=m-max_int;
        }
        cout<<ans<<endl<<counter<<endl;
    }
}