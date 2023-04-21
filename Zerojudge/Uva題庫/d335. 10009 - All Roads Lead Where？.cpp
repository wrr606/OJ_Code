//d335. 10009 - All Roads Lead Where?
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t,n,m;
    string s1,s2;
    bool b=0;
    cin>>t;
    while(t--){
        cin>>m>>n;
        unordered_map<char,char> tree;
        for(int i=0;i<m;i++){
            cin>>s1>>s2;
            tree[s2[0]]=s1[0];
        }
        for(int i=0;i<n;i++){
            vector<char> ans1,ans2;
            cin>>s1>>s2;
            ans1.push_back(s1[0]);
            while(s1[0]!='R'){
                s1[0]=tree[s1[0]];
                ans1.push_back(s1[0]);
            }
            ans2.push_back(s2[0]);
            while(s2[0]!='R'){
                s2[0]=tree[s2[0]];
                ans2.push_back(s2[0]);
            }
            int ans1_pointer=ans1.size()-1,ans2_pointer=ans2.size()-1;
            while(ans1[ans1_pointer]==ans2[ans2_pointer]){
                ans1_pointer--,ans2_pointer--;
            }
            for(int j=0;j<=ans1_pointer;j++){
                cout<<ans1[j];
            }
            for(int j=ans2_pointer+1;j>=0;j--){
                cout<<ans2[j];
            }
            cout<<endl;
        }
    }
}