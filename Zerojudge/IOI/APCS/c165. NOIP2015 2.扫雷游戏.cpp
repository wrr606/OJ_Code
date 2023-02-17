#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,counter=1;
	while(cin>>n&&cin>>m&&n&&m){
		vector<vector<int> > x(n+2,vector<int>(m+2));//int x[n+2][m+2]={};0 1 2 3 4 5
		string y;
		getline(cin,y);
		for(int i=1;i<n+1;i++){
			getline(cin,y);
			for(int j=1;j<m+1;j++){
				if(y[j-1]=='*'){
					x[i][j]=-99999;
					x[i+1][j+1]++;
					x[i+1][j]++;
					x[i][j+1]++;
					x[i-1][j]++;
					x[i][j-1]++;
					x[i-1][j-1]++;
					x[i-1][j+1]++;
					x[i+1][j-1]++;
				}
			}
		}
		for(int i=1;i<n+1;i++){
			for(int j=1;j<m+1;j++){
				if(x[i][j]<0){
					cout<<"*";
				}
				else{
					cout<<x[i][j];
				}
			}
			cout<<endl;
		}
		counter++;
	}
}