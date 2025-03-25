#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	while(cin>>n){
		string y;
		getline(cin,y);
		getline(cin,y);
		for(;n>0;n--){
			float total=0;
			map<string,int> tree;
			while(getline(cin,y)&&y!=""){
				total++;
				tree[y]++;
			}
			//sort(tree.begin(),tree.end());
			for(const auto &i : tree){
				cout<<i.first<<" ";
				printf("%.4f\n",i.second/total*100);
			}
		}
	}
}