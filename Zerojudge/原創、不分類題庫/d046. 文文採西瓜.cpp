//d046. 文文採西瓜
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    vector<int> x(n);
    n=0;
    for(auto &i:x){
        cin>>i;
        if(i<=10)
            n++;
    }
    cout<<n<<endl;
}