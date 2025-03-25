#include<iostream>
#include<math.h>
#include<string.h>
#include<ctype.h>
using namespace std;
int main(){
	//123456789 x[]
	//x[2]
	char x[9999]={};
	while(cin>>x){
		char y[9999]={};
		int len=strlen(x),z[9999]={},counter[9999]={},booln=0;
		for(int i=0;i<len;i++){
			x[i]=tolower(x[i]);
		}
		for(int j=0;j<len;j++){
			if(ispunct(x[j])||isspace(x[j])){
				for(int a=j;a<len;a++){
					x[a]=x[a+1];
				}
				j--;
			}
		}
		len=strlen(x);//ababa
					  //00000
		for(int c=0;c<len;c++){
			for(int d=0;d<len;d++){
				if(x[d]!='\0'){
					y[c]=x[d];
					for(int e=0;e<len;e++){
						if(y[c]==x[e]){
							x[e]='\0';
							counter[c]++;
						}
					}
					break;
				}
			}
		}
		for(int f=0;f<len;f++){
			if(counter[f]%2==1){
				booln++;
			}
		}
		
		if(booln>1){
			cout<<"no...\n";
		}
		else{
			cout<<"yes !\n";
		}
	}
}