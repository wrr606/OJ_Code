//k734. 4. 開啟寶盒
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m,k,t;
    cin>>n>>m>>k>>t;
    vector<int> key;
    vector<vector<int> > box(m,vector<int>());
    vector<vector<int> > in_box_key(n,vector<int>());
    vector<int> box_counter(n,k);
    vector<bool> invited(m,0);
    for(int i=0;i<t;i++){
        int temp;
        cin>>temp;
        key.push_back(temp);
        invited[temp]=1;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            int temp;
            cin>>temp;
            box[temp].push_back(i);
        }
    }
    for(auto &i:in_box_key){
        for(int j=0;j<k;j++){
            int temp;
            cin>>temp;
            i.push_back(temp);
        }
    }
    int ans=0;
    while(!key.empty()){
        int back=key.back();
        key.pop_back();
        for(auto i:box[back]){
            box_counter[i]--;
            if(box_counter[i]==0){
                for(auto j:in_box_key[i]){
                    if(!invited[j]){
                        key.push_back(j);
                        invited[j]=1;
                    }
                }
                ans++;
            }
        }
    }
    cout<<ans<<endl;
}