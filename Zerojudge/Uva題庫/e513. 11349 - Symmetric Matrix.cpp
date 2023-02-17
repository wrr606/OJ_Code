#include<bits/stdc++.h>
using namespace std;
int main(){
	vector<vector<long long int>> matrix(100,vector<long long int>(100));
	int a,n;
	while(cin>>a){
		string s;
		for(int counter=1;counter<=a;counter++){
			bool f=0,symmetric=1;
			n=0;
			cin>>s>>s>>n;
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					cin>>matrix[i][j];
					if(matrix[i][j]<0){
						f=1;
					}
				}
			}
			if(f){
				cout<<"Test #"<<counter<<": ";
				cout<<"Non-symmetric.\n";
				continue;
			}
			if(n%2==0){
				for(int i=0;i<n/2;i++){
					for(int j=0;j<n;j++){
						if(matrix[i][j]!=matrix[n-i-1][n-j-1]){
							symmetric=0;
							break;
						}
					}
					if(!symmetric)
						break;
				}
			}
			else{
				for(int i=0;i<=n/2;i++){
					for(int j=0;j<n;j++){
						if(matrix[i][j]!=matrix[n-i-1][n-j-1]){
							symmetric=0;
						}
					}
					if(!symmetric)
						break;
				}
			}
			cout<<"Test #"<<counter<<": ";
			if(symmetric){
				cout<<"Symmetric.\n";
			}
			else{
				cout<<"Non-symmetric.\n";
			}
		}
	}
}