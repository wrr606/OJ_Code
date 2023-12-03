//d183. 00725 - Division
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

bool isrepeat(int i,int a){
    bitset<10> check;
    if(i<10000||a<10000)
        check[0]=1;
    while(i){
        if(check[i%10])
            return 0;
        check[i%10]=1;
        i/=10;
    }
    while(a){
        if(check[a%10])
            return 0;
        check[a%10]=1;
        a/=10;
    }
    return 1;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    bool b=0;
    while(cin>>n&&n){
        bool ans=0;
        if(b)
            cout<<endl;
        b=1;
        for(int i=1234;i<=98765;i++){
            int a=i*n;
            if(a>98765||(a<10000&&i<10000))
                continue;
            if(isrepeat(i,a)){
                cout<<a<<" / "<<setw(5)<<setfill('0')<<i<<" = "<<n<<endl;
                ans=1;
            }
        }
        if(!ans)
            cout<<"There are no solutions for "<<n<<".\n";
    }
}