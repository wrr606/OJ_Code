#include<bits/stdc++.h>
using namespace std;

int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	while(cin>>n){
		vector<int> x(n);
		map<int,int> y;
		for(int o=0;o<n;o++){
			cin>>x[o];
			y[x[o]]=1;
		}
		vector<int> z;
		sort(x.begin(),x.end());
		for(auto i:x){
			cout<<i<<" ";
		}
		cout<<endl;
		for(auto i:y){
			z.push_back(i.first);
		}
		for(int i=z.size()-1;i>=0;i--){
			cout<<z[i]<<" ";
		}
		cout<<endl;
	}
}