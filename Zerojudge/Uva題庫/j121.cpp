//j121. 01339 - Ancient Cipher
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

bool cmp(pair<char,int> a,pair<char,int> b){
    return a.second>b.second;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    vector<pair<char,int> > dict1,dict2;
    unordered_map<char,int> a;
    string x,y;
    while(cin>>x>>y){
        dict1.clear(),dict2.clear(),a.clear();
        for(auto i:x){
            a[i]++;
        }
        for(auto i:a){
            dict1.push_back({i.first,i.second});
        }
        a.clear();
        for(auto i:y){
            a[i]++;
        }
        for(auto i:a){
            dict2.push_back({i.first,i.second});
        }
        bool b=1;
        sort(dict1.begin(),dict1.end(),cmp),sort(dict2.begin(),dict2.end(),cmp);
        for(int i=0;i<dict1.size();i++){
            if(dict1[i].second!=dict2[i].second){
                b=0;
                break;
            }
        }
        if(b)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}