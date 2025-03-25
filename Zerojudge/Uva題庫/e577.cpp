//e577. 10042 - Smith Numbers
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

int int_to_sum(int x){
    int sum=0;
    while(x){
        sum+=x%10;
        x/=10;
    }
    return sum;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t,n;
    cin>>t;
    for(int c=0;c<t;c++){
        cin>>n;
        ++n;
        while(true){
            int temp=n,ans=0;
            for(int i=2;i<=sqrt(n);i+=(i==2)?1:2){
                while(temp%i==0){
                    ans+=int_to_sum(i);
                    temp/=i;
                }
            }
            if(temp==n){
                n++;
                continue;
            }
            if(temp!=1){
                ans+=int_to_sum(temp);
            }
            if(int_to_sum(n)==ans){
                cout<<n<<endl;
                break;
            }
            else{
                n++;
            }
        }
    }
}