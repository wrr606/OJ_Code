#include<bits/stdc++.h>
using namespace std;
int main(){
	string x;
	while(getline(cin,x)){
		string q="`1234567890-=qwertyuiop[]\ asdfghjkl;'zxcvbnm,./";
		for(int i=0;i<x.size();i++){
			if(x[i]==' '||x[i]=='`'||x[i]=='1'||x[i]=='q'||x[i]=='w'||x[i]=='a'||x[i]=='s'||x[i]=='z'||x[i]=='x'){
				cout<<x[i];
			}
			else if(x[i]==92){
				cout<<"[";
			}
			else{
				for(int j=0;j<q.size();j++){
					if(x[i]==q[j]){
						cout<<q[j-2];
						break;
					}
				}
			}
		}
		cout<<endl;
	}
}