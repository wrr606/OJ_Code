//1152 4 Values whose Sum is 0
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,t,numbers[4][4001],ans;
    bool blank=0;
    cin>>t;
    while(t--){
        if(blank)
            cout<<endl;
        blank=1;
        cin>>n;
        ans=0;
        unordered_map<int,int> c_and_d;
        vector<int> a_and_b;
        for(int i=0;i<n;i++){
            for(int j=0;j<4;j++){
                cin>>numbers[j][i];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                a_and_b.push_back(numbers[0][i]+numbers[1][j]);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                c_and_d[-numbers[2][i]-numbers[3][j]]++;
            }
        }
        for(const auto &i:a_and_b)
            if(c_and_d[i])
                ans+=c_and_d[i];
        cout<<ans<<endl;
    }
}