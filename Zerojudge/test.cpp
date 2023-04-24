#include<iostream>
#include<Windows.h>
using namespace std;
const int all_block_num=100;
int main(){
	for(int i=0;i<all_block_num;i++){
		printf("\r[%d%%]>",i*100/(all_block_num-1));
		for(int j=1;j<=i*20/all_block_num;j++){
			cout<<"▉";
			Sleep(10);
		}
	}
	return 0;
}