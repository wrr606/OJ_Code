#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    unsigned long long int sum=0,s=0;
	int n;
    while(cin>>n){
        sum=0,s=0;
        vector<int> a(n);
        cin>>a[0];
        s+=a[0];
        for(int i=1;i<n;i++){
            cin>>a[i];
            sum+=s*a[i];
            s+=a[i];
        }
        cout<<sum<<endl;
    }
}