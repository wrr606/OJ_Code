#include<bits/stdc++.h>
using namespace std;

int main(){
	queue<int> que;
	int n,k;
	cin>>n;
	for(;n>0;n--){
		cin>>k;
		switch(k){
		case 1:
			cin>>k;
			que.push(k);
			break;
		case 2:
			if(que.empty()){
				cout<<-1<<endl;
			}
			else{
				cout<<que.front()<<endl;
			}
			break;
		case 3:
			if(!que.empty()){
				que.pop();
			}
			break;
		}
	}
}