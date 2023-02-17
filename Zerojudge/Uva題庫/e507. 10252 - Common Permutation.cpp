#include<bits/stdc++.h>
using namespace std;
int main(){
	string a,b,c="";
	while(getline(cin,a)&&getline(cin,b)){
		if(b.size()<a.size()){
			c=b;
			b=a;
			a=c;
		}
		c="";
		for(int i=0;i<a.size();i++){
			for(int j=0;j<b.size();j++){
				if(a[i]==b[j]){
					c+=a[i];
					b.erase(j,1);
					break;
				}
			}
		}
		sort(c.begin(),c.end());
		cout<<c<<endl;
	}
}