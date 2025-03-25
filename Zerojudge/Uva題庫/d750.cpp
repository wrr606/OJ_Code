#include<bits/stdc++.h>
using namespace std;

int main(){
	int n=1,m=1;
	while(cin>>n>>m){
		if(n==0&&m==0){
			cout<<"0 0";
			break;
		}
		else{
			cout<<n<<" "<<m<<endl;
		}
		vector<int> x;
		vector<int> y;
		int temp,o;
		for(int i=0;i<n;i++){
			cin>>temp;
			x.push_back(temp);
			y.push_back(temp%m);
		}
		//select_sort
		for(int i=0;i<n;i++){
			temp=9999;
			for(int j=i;j<n;j++){
				if(temp>=y[j]){
					temp=y[j];
					o=j;
				}
			}
			swap(y[o],y[i]);
			swap(x[o],x[i]);
		}
		temp=y[0];//1 1 1 2 2 3 3 3
		vector<int> odd;
		vector<int> even;
		/* 
		for(int i=0;i<n;i++){
			cout<<x[i]<<endl;
		}
		*/ 
		for(int i=0;i<n;i++){
			if(temp==y[i]&&i!=n-1){
				if(x[i]%2==0){
					even.push_back(x[i]);
				}
				else{
					odd.push_back(x[i]);
				}
			}
			else{
				temp=y[i];
				sort(even.begin(),even.end());
				sort(odd.begin(),odd.end());
				for(int j=odd.size()-1;j>=0;j--){
					cout<<odd[j]<<endl;
				}
				for(auto j:even){
					cout<<j<<endl;
				}
				odd.clear();
				even.clear();
				if(x[i]%2==0){
					even.push_back(x[i]);
				}
				else{
					odd.push_back(x[i]);
				}
			}
		}
		cout<<x[n-1]<<endl;
	}
}