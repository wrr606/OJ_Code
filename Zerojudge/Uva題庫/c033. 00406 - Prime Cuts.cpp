//c033. 00406 - Prime Cuts
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

set<int> prime{1,2,3};

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    //質數建表
    for(int i=5;i<=1000;i++){
        bool b=true;
        for(int j=2;j<=sqrt(i);j+=(j==2)?1:2){
            if(i%j==0){
                b=false;
                break;
            }
        }
        if(b)
            prime.insert(i);
    }
    int n,c;
    while(cin>>n){
        cin>>c;
        cout<<n<<" "<<c<<": ";
        //0 1 2 3 
        vector<int> x;
        auto max=prime.lower_bound(n);
        auto iter=prime.begin();
        for(iter;iter!=max;iter++){
            x.push_back(*iter);
        }
        if(*iter==n)
            x.push_back(n);
        if(x.size()<=c*2-1)
            for(auto i:x)
                cout<<i<<" ";
        else if(x.size()%2==1)
            for(int i=x.size()/2-c+1;i<=x.size()/2+c-1;i++)
                cout<<x[i]<<" ";
        else if(x.size()%2==0)
            for(int i=x.size()/2-c;i<=x.size()/2+c-1;i++)
                cout<<x[i]<<" ";
        cout<<endl;
    }
}