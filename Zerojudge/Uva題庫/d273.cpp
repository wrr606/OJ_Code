#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

string s;
int dp[1005]={};

bool palindrome(int left,int right){
    while(right>left){
        if(s[left]!=s[right])
            return 0;
        right--;
        left++;
    }
    return 1;
}

int main(){
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    while(n--){
        s=" ";
        string temp;
        cin>>temp;
        s+=temp;
        memset(dp,9999999,sizeof(dp));
        dp[0]=0;
        for(int i=1;i<=s.size();i++){
            for(int j=1;j<=i;j++){
                if(palindrome(j,i))
                    dp[i]=min(dp[j-1]+1,dp[i]);
            }
        }/*
        for(int i=0;i<=s.size();i++)
            cout<<dp[i]<<endl;*/
        cout<<dp[s.size()-1]<<endl;
    }
}