//Gray_Code
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define all(x) x.begin(),x.end() 
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<ll> vll;

//快速冪
int qpow(int a,int n){
    int res=1;
    while(n){
        if(n&1)
            res*=a;
        a*=a;
        n>>=1;
    }
    return res;
}

char bar(char c){
    if(c=='0')
        return '1';
    return '0';
}

void print(string &s,int n){
    bool b=1;
    while(n--){
        cout<<s<<endl;
        if(b)
            s[s.size()-1]=bar(s[s.size()-1]);
        else{
            for(int i=s.size()-1;i>0;i--)
                if(s[i]=='1'){
                    s[i-1]=bar(s[i-1]);
                    break;
                }
        }
        b=!b;
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    string s="";
    cin>>n;
    for(int i=0;i<n;i++)
        s+="0";
    print(s,qpow(2,n));
}
/*
0  　　 000    000
1  　　 001    001
2   　　011    010
3   　　010    011
4   　　110    100
5   　　111    101
6   　　101    110
7   　　100    111
*/