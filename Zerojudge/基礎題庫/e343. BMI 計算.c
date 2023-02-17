#include<stdio.h>
int main(){
	float w,h;
	scanf("%f%f",&w,&h);
	printf("%.1f",w/((h/100)*(h/100)));
}