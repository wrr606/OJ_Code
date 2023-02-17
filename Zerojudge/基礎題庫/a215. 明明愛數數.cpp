#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
int main(){
	int n,m,num,counter;
	while(cin>>n>>m){
		num=0;
		counter=0;
		for(int i=n;;i++,counter++){
			num+=i;
			//cout<<counter<<endl;
			if(num>m){
				counter++;
				break;
			}
		}
		cout<<counter<<endl;
	}
}