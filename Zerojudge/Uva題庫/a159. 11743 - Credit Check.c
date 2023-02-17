#include<stdio.h>
int main(){
	//5181 2710 9900 0012
	int n;
	scanf("%d",&n);
	for(n;n>=1;n--){
		char in[20]={};
		scanf("%s %s %s %s",&in[0],&in[4],&in[8],&in[12]);
		int counter=0;//0 2 5 7 10 12 15 17
		for(int i=0;i<=15;i+=2){
				counter+=(2*((int)in[i]-48))/10+(2*((int)in[i]-48))%10;
		}
		for(int i=1;i<=15;i+=2){
				counter+=(int)in[i]-48;
		}
		if(counter%10==0){
			printf("Valid\n");
		}
		else{
			printf("Invalid\n");
		}
	}
}