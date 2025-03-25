#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	while(cin>>n){
		int d,mid1=0,mid2=0,counter=0;
		vector<int> x;
		for(int i=n;i>=1;i--){
			cin>>d;
			x.push_back(d);
		}
		sort(x.begin(),x.end());
		//mid number
		if(n%2==0){
			mid1=x[n/2-1];
			mid2=x[n/2];
		}
		else{
			mid1=x[n/2];
			mid2=mid1;
		}
		for(int i=0;i<n;i++){
			if(mid1==x[i]||mid2==x[i])
				counter++;
		}
		cout<<mid1<<" "<<counter<<" "<<1-mid1+mid2<<"\n";
	}
}