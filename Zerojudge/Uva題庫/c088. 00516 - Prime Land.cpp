//c088. 00516 - Prime Land
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

vector<int> number;

//快速冪
ll qpow(ll x,ll y){
    ll ans=1;
    while(y>0){
        if(y&1==1)
            ans*=x;
        x*=x;
        y>>=1;
    }
    return ans;
}

void spilt(string s){
    string temp="";
    while(s!=""){
        if(s[0]==' '){//100 12
            //cout<<temp<<endl;
            number.push_back(stoi(temp));
            s.erase(0,1);
            temp="";
        }
        else{
            temp+=s[0];
            s.erase(0,1);
        }
    }
    number.push_back(stoi(temp));
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    string s;
    int ans;
    while(getline(cin,s)&&s!="0"){
        ans=1;
        number.clear();
        spilt(s);
        for(int i=0;i<number.size()-1;i+=2){
            ans*=qpow(number[i],number[i+1]);
        }
        ans--;
        //cout<<ans<<endl;
        map<int,int> dict;
        int prime=2;
        while(ans>1){
            if(ans%prime==0){
                ans/=prime;
                dict[prime]++;
                continue;
            }
            prime+=(prime==2)?1:2;
        }
        for(auto iter=dict.rbegin();iter!=dict.rend();iter++){
            cout<<iter->first<<" "<<iter->second<<" ";
        }
        cout<<endl;
    }
}