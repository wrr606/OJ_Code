#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	int gcd,lcm;
	while(n--){
		cin>>gcd>>lcm;
		//x*y=lcm*gcd	3 4
		if(lcm%gcd==0){
			cout<<gcd<<" "<<lcm<<'\n';
		}
		else
			cout<<"-1\n";
	}
}