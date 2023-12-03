#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	while(cin>>n){
		int count=1;
		vector<int> x={0,0};
		for(;n>0;n--){
			int counter=0;
			cin>>x[0]>>x[1];
			sort(x.begin(),x.end());
			if(x[1]%2==0)x[1]--;
			if(x[0]%2==0)x[0]++;
			for(int i=x[0];i<=x[1];i+=2){
				counter+=i;
			}
			cout<<"Case "<<count<<": "<<counter<<endl;
			count++;
		}
	}
}