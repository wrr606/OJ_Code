#include<iostream>
#include<math.h>
using namespace std;
int main(){
	int n;
	cin>>n;//2
	int x[n][2]={},an[n]={};//4
	for(int q=0;q<n;q++){
		cin>>x[q][0]>>x[q][1];
	}
	for(int i=0;i<n;i++){
		for(int j=x[i][0];j<=x[i][1];j++){
			if(j==pow((int)pow(j,0.5),2)){
				an[i]=an[i]+j;
			}
		}
	}
	for(int l=0;l<n;l++){
		cout<<"Case "<<l+1<<": "<<an[l]<<endl;
	}
}