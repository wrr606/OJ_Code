//a223. 10298 - Power Strings
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    string s,temp;
    while(cin>>s&&s!="."){
        int lenght_s=s.size(),lenght_temp=0,max=0,counter;
        bool b=1;
        temp="";
        for(int i=0;i<lenght_s;i++){
            if(max<counter)
                max=counter;
            b=1,counter=1;
            temp+=s[i],lenght_temp++;
            if(lenght_s%lenght_temp)
                continue;
            for(int j=lenght_temp;j<lenght_s;j+=lenght_temp){
                for(int k=0;k<lenght_temp;k++){
                    if(s[j+k]!=temp[k]){
                        b=0;
                        counter=0;
                        break;
                    }
                }
                counter++;
                if(!b)
                    break;
            }
        }
        cout<<max<<endl;
    }
}