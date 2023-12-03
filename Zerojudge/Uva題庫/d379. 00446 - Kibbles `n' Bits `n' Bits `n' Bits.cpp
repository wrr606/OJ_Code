#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

int hex_int(string s){
    int lenght=s.size(),counter=0;
    for(int i=0;i<lenght;i++){
        if((int)s[lenght-1-i]>=65)
            counter+=((int)s[lenght-1-i]-55)*pow(16,i);
        else
            counter+=((int)s[lenght-1-i]-48)*pow(16,i);
    }
    return counter;
}

string int_bin(int x){
    //8 1000
    string s;
    while(x){
        s+=char(x%2+48);
        x/=2;
    }
    int lenght=s.size();
    if(lenght<13){
        for(int i=1;i<=13-lenght;i++)
            s+="0";
    }
    reverse(s.begin(),s.end());
    return s;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,s11,s22;
    string s1,s2,sign;
    cin>>n;
    while(n--){
        cin>>s1>>sign>>s2;
        s11=hex_int(s1);
        s22=hex_int(s2);
        cout<<int_bin(s11)<<" "<<sign<<" "<<int_bin(s22)<<" = ";
        if(sign=="+")
            cout<<s11+s22<<endl;
        else
            cout<<s11-s22<<endl;
    }
}
//13