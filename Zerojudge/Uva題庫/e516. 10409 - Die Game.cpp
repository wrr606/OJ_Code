#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	while(cin>>n&&n){
		vector<int> dice={2,6,5,1,3,4};
		string dir;
		getline(cin,dir);
		for(int i=0;i<n;i++){
			getline(cin,dir);
			if(dir=="north"){
				int tem=dice[3];
				for(int j=3;j>0;j--){
					dice[j]=dice[j-1];
				}
				dice[0]=tem;
			}
			else if(dir=="south"){
				int tem=dice[0];
				for(int j=1;j<4;j++){
					dice[j-1]=dice[j];
				}
				dice[3]=tem;
			}
			else if(dir=="west"){
				int tem=dice[5];
				dice[5]=dice[1];
				dice[1]=dice[4];
				dice[4]=dice[3];
				dice[3]=tem;
			}
			else{
				int tem=dice[5];
				dice[5]=dice[3];
				dice[3]=dice[4];
				dice[4]=dice[1];
				dice[1]=tem;
			}
		}
		cout<<dice[3]<<endl;
	}
}