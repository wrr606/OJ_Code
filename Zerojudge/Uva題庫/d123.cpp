#include<bits/stdc++.h>
using namespace std;


int main(){
	int n,counter=1;
	while(cin>>n){
		vector<int> sequence;
		vector<int> x;
		for(int i=0;i<9999;i++){
			x.push_back(0);
		}
		int temp;
		bool booln=0;
		for(int i=0;i<n;i++){
			cin>>temp;
			sequence.push_back(temp);
		}
		for(int i=0;i<n;i++){
			for(int j=i;j<n;j++){
				if(x[sequence[i]+sequence[j]]){
					booln=1;
					break;
				}
				else{
					x[sequence[i]+sequence[j]]=1;
				}
			}
			if(booln){
				break;
			}
		}
		cout<<"Case #"<<counter<<": ";
		if(booln){
			cout<<"It is not a B2-Sequence.\n";
		}
		else{
			cout<<"It is a B2-Sequence.\n";
		}
		counter++;
	}
}