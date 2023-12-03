#include<bits/stdc++.h>
using namespace std;

int main(){
	vector<int> x0;
	vector<int> y0;
	int n;
	while(cin>>n){
		x0.clear();
		y0.clear();
		int temp;
		for(int i=0;i<n;i++){
			cin>>temp;
			x0.push_back(temp);
			cin>>temp;
			y0.push_back(temp);
		}
		//select sort
		int min;
		for(int i=0;i<n;i++){
			min=999999;
			for(int j=0;j<n;j++){
				if(x0[j]<=min){
					min=x0[j];
					temp=j;
				}
			}
			cout<<min<<" ";
			int mi=min,te;
			min=y0[temp];
			te=temp;
			for(int j=0;j<n;j++){
				if(x0[j]==mi){
					if(min>y0[j]){
						min=y0[j];
						te=j;
					}
				}
			}
			cout<<min<<endl;
			x0[te]=999999;
			y0[te]=999999;
		}
	}
}