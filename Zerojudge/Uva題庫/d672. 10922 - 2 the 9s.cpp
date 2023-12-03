#include<bits/stdc++.h>
using namespace std;

string str(int x){
	string s;
	while(x!=0){
		s+=(char)(x%10+48);
		x/=10;
	}
	reverse(s.begin(),s.end());
	return s;
}

int recursion_9(string s,int counter=0){
	//999=9+9+9=27=2+7=9
	int count=0;
	for(auto i:s){
		count+=(int)(i)-48;
	}
	if(count==9){
		return counter;
	}
	else{
		return recursion_9(str(count),++counter);
	}
}

int main(){
	string s;
	while(cin>>s&&s!="0"){
		int counter=0;
		for(auto i:s){
			counter+=(int)i-48;
		}
		if(counter%9==0){
			cout<<s<<" is a multiple of 9 and has 9-degree "<<recursion_9(s)+1<<".\n";
		}
		else{
			cout<<s<<" is not a multiple of 9."<<endl;
		}
	}
}