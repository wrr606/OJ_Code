#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t,multiples_of_three,sum=0;
    string s;
    cin>>t;
    for(int counter=1;counter<=t;counter++){
        sum=0,multiples_of_three=0;
        cin>>s;
        cout<<"Case "<<counter<<": ";
        for(auto i:s){
            //***remember 0***
            if(i=='0'||i=='3'||i=='6'||i=='9')
                multiples_of_three++;
            sum+=int(i-48);
        }
        if(sum%3){
            for(auto i:s){
                if(!((sum-int(i-48))%3)){
                    multiples_of_three++;
                    break;
                }
            }
        }
        //cout<<multiples_of_three<<endl<<sum<<endl;
        if(multiples_of_three%2)
            cout<<"S\n";
        else
            cout<<"T\n";
    }
}