//k468. 打靶 (Target)
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,s,f,counter=1;
    cin>>n>>s>>f;
    vector<int> x(n);
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
    while(1){
        if(x.front()==f)
            s--;
        if(!s){
            cout<<counter<<endl;
            break;
        }
        int first=*(x.begin());
        x.erase(x.begin());
        auto iter=find(all(x),first);
        if(iter!=x.end()){
            if(*iter==f)
                s--;
            x.erase(iter);
        }
        if(!s){
            cout<<counter<<endl;
            break;
        }
        counter++;
    }
}
/*
10 3 5
1 7 6 1 5 4 5 5 3 1
*/