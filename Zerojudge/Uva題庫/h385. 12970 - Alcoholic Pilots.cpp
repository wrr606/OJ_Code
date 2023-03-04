#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long int v1,d1,v2,d2,gcd,ans1,ans2,counter=1;
    double t1,t2;
    while(cin>>v1>>d1>>v2>>d2&&v1&&d1&&v2&&d2){
        t1=(double)d1/v1,t2=(double)d2/v2;
        if(t2>t1)
            cout<<"Case #"<<counter<<": You owe me a beer!\n";
        else
            cout<<"Case #"<<counter<<": No beer for the captain.\n";
        cout<<"Avg. arrival time: ";
        ans1=d1*v2+d2*v1;
        ans2=2*v1*v2;
        gcd=__gcd(ans1,ans2);
        ans1/=gcd,ans2/=gcd;
        if(ans2==1)
            cout<<ans1<<endl;
        else
            cout<<ans1<<"/"<<ans2<<endl;
        counter++;
    }
}