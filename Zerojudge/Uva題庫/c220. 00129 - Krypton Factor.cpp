//c220. 00129 - Krypton Factor
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

int n,l,counter;
char s[100]={};
bool ans=0;

void DFS(int cur_length=0){
    //cout<<cur_length<<endl;
    if(counter==n){
        for(int i=0;i<cur_length;i++){
            if(i!=0&&i%4==0){
                if(i==64)
                    cout<<endl<<s[i];
                else
                    cout<<" "<<s[i];
            }
            else{
                cout<<s[i];
            }
        }
        ans=1;
        cout<<endl<<cur_length<<endl;
    }
    else{
        for(int i=0;i<l;i++){
            s[cur_length]='A'+i;
            bool wrong=0;
            for(int j=1;j*2<=cur_length+1;j++){
                wrong=1;
                for(int k=0;k<j;k++){
                    if(s[cur_length-k]!=s[cur_length-k-j]){
                        wrong=0;
                        break;
                    }
                }
                if(wrong)
                    break;
            }
            if(!wrong){
                counter++;
                if(!ans)
                    DFS(cur_length+1);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    while(cin>>n>>l&&n&&l){
        counter=0,ans=0;
        DFS();
    }
}