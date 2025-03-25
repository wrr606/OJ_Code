//d088. 00127 - "Accordian" Patience
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

bool match(string x,string y){
    return x[0]==y[0]||x[1]==y[1];
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    string temp;
    while(cin>>temp&&temp!="#"){
        bool ending=1;
        vector<vector<string> > poker(52);
        poker[0].push_back(temp);
        for(int i=1;i<52;i++){
            cin>>temp;
            poker[i].push_back(temp);
        }
        while(ending){
            //cout<<poker.size()<<endl;
            ending=0;
            for(int i=0;i<poker.size();i++){
                if(i-3>=0){
                    if(match(poker[i].back(),poker[i-3].back())){
                        poker[i-3].push_back(poker[i].back());
                        poker[i].pop_back();
                        if(poker[i].empty())
                            poker.erase(poker.begin()+i);
                        ending=1;
                        break;
                    }
                }
                if(i-1>=0){
                    if(match(poker[i].back(),poker[i-1].back())){
                        poker[i-1].push_back(poker[i].front());
                        poker[i].pop_back();
                        if(poker[i].empty())
                            poker.erase(poker.begin()+i);
                        ending=1;
                        break;
                    }
                }
            }
        }
        if(poker.size()==1){
            cout<<"1 pile remaining: 52\n";
        }
        else{
            cout<<poker.size()<<" piles remaining: ";
            for(int i=0;i<poker.size()-1;i++)
                cout<<poker[i].size()<<" ";
            cout<<poker[poker.size()-1].size()<<endl;
        }
    }
}