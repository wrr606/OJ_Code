#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,k,a,b;
    string s1,s2;
    map<int,int> member_win;
    map<int,int> member_lose;
    map<string,int> gesture={{"scissors",0},{"rock",1},{"paper",2}};
    bool space = false;
    while(cin>>n&&n){
        cin>>k;
        if( space ) printf( "\n" );
        space = true;
        member_win.clear();
        member_lose.clear();
        for(int i=1;i<=n;i++){
            member_win[i]=0;
            member_lose[i]=0;
        }
        for(int o=0;o<k*n*(n-1)/2;o++){
            cin>>a>>s1>>b>>s2;
            if(s1=="scissors"&&s2=="paper"){
                member_win[a]++;
                member_lose[b]++;
            }
            else if(s1=="paper"&&s2=="scissors"){
                member_win[b]++;
                member_lose[a]++;
            }
            else if(gesture[s1]>gesture[s2]){
                member_win[a]++;
                member_lose[b]++;
            }
            else if(gesture[s1]<gesture[s2]){
                member_win[b]++;
                member_lose[a]++;
            }
        }
        for(int i=1;i<=n;i++){
            if(member_win[i]+member_lose[i]==0){
                printf("-\n");
            }
            else{
                printf("%.3lf\n",(double)member_win[i]/((double)member_win[i]+(double)member_lose[i]));
            }
        }
    }
}