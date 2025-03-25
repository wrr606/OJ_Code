#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	while(cin>>n&&n){
		if(n==1){
			cout<<"Discarded cards:\nRemaining card: 1\n";
			continue;
		}
		queue<int> x;
		for(int i=1;i<=n;i++){
			x.push(i);
		}
		cout<<"Discarded cards: ";
		for(int i=0;i<n-2;i++){
			cout<<x.front()<<", ";
			x.pop();
			x.push(x.front());
			x.pop();
		}
		cout<<x.front()<<"\n";
		x.pop();
		x.push(x.front());
		cout<<"Remaining card: "<<x.front()<<endl;
	}
}