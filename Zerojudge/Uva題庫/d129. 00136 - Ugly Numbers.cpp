#include<bits/stdc++.h>
using namespace std;

int main(){
	int counter=16;
	int count=12,n;
	vector<int> num={1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15};
while(count<=1501){
    n=counter;
    while(n%2==0)
        n/=2;
    while(n%3==0)
        n/=3;
    while(n%5==0)
        n/=5;
    if(n==1){
        //cout<<counter<<endl;
        num.push_back(counter);
        count+=1;
	}
    counter+=1;
}
cout<<"The 1500'th ugly number is "<<num[1499]<<".";
}