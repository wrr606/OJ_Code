#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
int main(){
	int n;
	while(cin>>n){
			
		int dic[8]={1,2,3,4,5,6,7,8};
		reverse(dic,dic+n);
		do{
			for(int j=0;j<=n-1;j++){
				cout<<dic[j];
			}
			cout<<endl;
		}while(prev_permutation(dic,dic+n));
	}
	
}