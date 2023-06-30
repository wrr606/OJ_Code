//d194. 11572 - Unique Snowflakes
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

int main(){//greedy algorithm
    ios::sync_with_stdio(0),cin.tie(0);
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> number(n);
        unordered_set<int> sequence;
        int ans=0,r=0;
        for(auto &i:number)
            cin>>i;
        for(int l=0;l<n&&r<n;l++){
            if(l>r){
                l=r-1;
                int length=sequence.size();
                ans=max(ans,length);
                sequence.clear();
                continue;
            }
            if(sequence.find(number[r])==sequence.end()){
                sequence.insert(number[r]);
                r++;
                int length=sequence.size();
                ans=max(ans,length);
                l--;
            }
            else{
                sequence.erase(number[l]);
            }
        }
        cout<<ans<<endl;
    }
}