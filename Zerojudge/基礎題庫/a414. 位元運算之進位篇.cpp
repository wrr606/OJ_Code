#include<iostream>
#include<string>
#include<math.h>
using namespace std;
int main() {
	int x,counter;
	while(scanf("%d",&x)){
		counter=0;
		if(x==0){
			return 0;
		}
		while(1){
			if(x%2==0){
				break;
			}
			else{
				counter++;
				x/=2;
			}
		}
		printf("%d\n",counter);
	}
}