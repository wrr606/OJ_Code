#include<bits/stdc++.h>
using namespace std;

stack<int> stack1;
queue<int> queue1;
vector<int> y(1000);

int main(){
	int n;
	while(cin>>n&&n){
		while(cin>>y[1]){
			if(y[1]==0){
				cout<<endl;
				break;
			}
			bool bo=0;
			for(int i=2;i<=n;i++){
				cin>>y[i];
			}
			for(int i=n;i>0;i--){
				queue1.push(y[i]);
			}
			int remaining=n;
			while(!queue1.empty()){//4 5 3 7 6 2 1
				if(queue1.front()==remaining){
					queue1.pop();
					remaining--;
				}
				else{
					if(!stack1.empty()){
						if(stack1.top()==remaining){
							stack1.pop();
							remaining--;
						}
						else{
							stack1.push(queue1.front());
							queue1.pop();
						}
					}
					else{
						stack1.push(queue1.front());
						queue1.pop();
					}
				}
			}
			while(!stack1.empty()){
				if(stack1.top()==remaining){
					stack1.pop();
					remaining--;
				}
				else{
					cout<<"No\n";
					int size=stack1.size();
					for(int i=0;i<size;i++){
						stack1.pop();
					}
					bo=1;
					break;
				}
			}
			if(bo){
				continue;
			}
			cout<<"Yes\n";
		}
	}
}
/*
5
1 2 3 4 5
5 4 3 2 1
5 4 1 2 3
0
7
4 5 3 7 6 2 1
0
0
*/