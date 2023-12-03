//b265. Q11286 - Conformity
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    while(cin>>n&&n){
        map<set<int>,int> dict;
        for(int c=0;c<n;c++){
            int temp;
            set<int> tempset;
            for(int i=0;i<5;i++){
                cin>>temp;
                tempset.insert(temp);
            }
            dict[tempset]++;
        }
        int max=-1;
        set<int> index;
        for(auto i:dict){
            if(max<=i.second){
                index=i.first;
                max=i.second;
            }
        }
        int counter=0;
        for(auto i:dict){
            if(i.second==dict[index])
                counter++;
        }
        cout<<counter*dict[index]<<endl;
    }
}