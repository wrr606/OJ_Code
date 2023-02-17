#include<bits/stdc++.h>
using namespace std;

int date[14]={0,0,31,59,90,120,151,181,212,243,273,304,334,365};

int main() {
	int n,month,day;
	while(cin>>n){
		for(;n>0;n--){
			cin>>month>>day;
			day+=date[month];
			switch(day%7){
				case 0:
					cout<<"Friday\n";
					break;
				case 1:
					cout<<"Saturday\n";
					break;
				case 2:
					cout<<"Sunday\n";
					break;
				case 3:
					cout<<"Monday\n";
					break;
				case 4:
					cout<<"Tuesday\n";
					break;
				case 5:
					cout<<"Wednesday\n";
					break;
				case 6:
					cout<<"Thursday\n";
					break;
			}
		}
	}
}