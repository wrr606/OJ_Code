//Palindrome_Reorder
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

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    string s,ans="";
    unordered_map<char,int> dict;
    cin>>s;
    for(const auto &i:s)
        dict[i]++;
    int odd_counter=0;
    char odd;
    for(const auto &i:dict)
        if(i.second&1)
            odd_counter++,odd=i.first;
    if(odd_counter>1)
        cout<<"NO SOLUTION";
    else{
        for(const auto &i:dict){
            if(i.first!=odd){
                for(int j=0;j<i.second/2;j++){
                    ans+=i.first;
                }
            }
        }
        string temp=ans;
        reverse(all(temp));
        for(int i=0;i<dict[odd];i++)
            ans+=odd;
        ans+=temp;
        cout<<ans;
    }
}