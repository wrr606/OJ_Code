#include<stdio.h>
#include<math.h>
int main(){
	int n,an;
	scanf("%d",&n);
	int x[n][3];
	for(int i=0;i<n;i++){
		scanf("%d %d %d",&x[i][0],&x[i][1],&x[i][2]);
		an=(int)pow(pow(x[i][1],2)-4*x[i][0]*x[i][2],0.5);
		if(pow(an,2)==(pow(x[i][1],2)-4*x[i][0]*x[i][2])){
			printf("Yes\n");
		}
		else{
			printf("No\n");
		}
	}
	return 0;
}