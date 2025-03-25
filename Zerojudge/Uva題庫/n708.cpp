//11360 Having Fun with Matrices
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t,r,n;
    string s;
    cin>>t;
    for(int c=1;c<=t;c++){
        cin>>r;
        vector<string> matrix(r);
        for(int i=0;i<r;i++){
            cin>>matrix[i];
        }
        cin>>n;
        while(n--){
            cin>>s;
            if(s[0]=='d'){
                for(auto &i:matrix){
                    for(auto &j:i){
                        if(j!='0')
                            j--;
                        else
                            j='9';
                    }
                }
            }
            else if(s[0]=='i'){
                for(auto &i:matrix){
                    for(auto &j:i){
                        if(j!='9')
                            j++;
                        else
                            j='0';
                    }
                }
            }
            else if(s[0]=='r'){
                int x,y;
                cin>>x>>y;
                swap(matrix[x-1],matrix[y-1]);
            }
            else if(s[0]=='c'){
                int x,y;
                cin>>x>>y;
                for(auto &i:matrix){
                    swap(i[x-1],i[y-1]);
                }
            }
            else{
                for(int i=0;i<r-1;i++){
                    for(int j=i+1;j<r;j++){
                        swap(matrix[i][j],matrix[j][i]);
                    }
                }
            }
        }
        cout<<"Case #"<<c<<endl;
        for(auto i:matrix){
            for(auto j:i){
                cout<<j;
            }
            cout<<endl;
        }
        cout<<endl;
    }
}