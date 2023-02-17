#include<bits/stdc++.h>
using namespace std;

int main() {
	vector<long long int> x={1};
    for(int i=2;i<=320;i++){
    	x.push_back(pow(i,2));
	}
	int n,m;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (cin>>n>>m){
    	int min,max;
        if (n==0&&m==0){
            break;
        }
        for(int i=0;i<320;i++){
        	if(x[i]>=n){
        		min=i;
        		break;
			}
		}
		for(int i=319;i>=0;i--){
			if(x[i]<=m){
				max=i;
				break;
			}
		}
		cout<<max-min+1<<endl;
    }
}