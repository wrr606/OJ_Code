#include<bits/stdc++.h>
using namespace std;

stack<int> stack1;
queue<int> queue1;
vector<int> y(1000);

int main(){
	int n;
	while(cin>>n){
		string s,output;
		char temp;
		int counter;
		for(int o=1;o<=n;o++){
			output="";
			counter=0;
			cin>>s;
			temp=s[0];
			for(int i=1;i<s.size();i++){
				if(!(s[i]<=57&&48<=s[i])){
					//cout<<temp<<"\t"<<counter<<endl;
					for(int j=0;j<counter;j++){
						output+=temp;
					}
					temp=s[i];
					counter=0;
				}
				else{
					counter*=10;
					counter+=(int)s[i]-48;
				}
			}
			for(int j=0;j<counter;j++){
						output+=temp;
			}
			cout<<"Case "<<o<<": "<<output<<endl;
		}
	}
}