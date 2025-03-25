#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	while(cin>>n){
		vector<int> ab={0,0};
		for(;n>0;n--){
			vector<float> xy={0,0};
			cin>>ab[0]>>ab[1];
			xy[0]=(ab[0]+ab[1])/2.0;
			xy[1]=(ab[0]-ab[1])/2.0;
			if(xy[1]<0||xy[1]-(int)xy[1]>0){
				cout<<"impossible\n";
				continue;
			}
			sort(xy.begin(),xy.end());
			cout<<xy[1]<<" "<<xy[0]<<endl;
		}
	}
}