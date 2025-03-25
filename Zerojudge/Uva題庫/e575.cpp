#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	while(cin>>n){
		for(;n>0;n--){
			int m,n,q;
			cin>>m>>n>>q;
			vector<string> squares;
			string s;
			for(int i=0;i<m;i++){
				cin>>s;
				squares.push_back(s);
			}
			cout<<m<<" "<<n<<" "<<q<<endl;
			int x,y;
			char temp;
			for(int o=0;o<q;o++){
				int counter=1,count=1;
				bool booln=0;
				cin>>y>>x;
				temp=squares[y][x];
				while(!booln){
					for(int i=y-counter;i<=y+counter;i++){
						for(int j=x-counter;j<=x+counter;j++){
							if(i<0||j<0||i>m-1||j>n-1){
								cout<<count<<endl;
								booln=1;
								break;
							}
							if(squares[i][j]!=temp){
								cout<<count<<endl;
								booln=1;
								break;
							}
						}
						if(booln){
							break;
						}
					}
					counter++;
					count+=2;
				}
			}
		}
	}
}
/*
a b b b a a a a a a		1 2
a b b b a a a a a a
a b b b a a a a a a
a a a a a a a a a a
a a a a a a a a a a
a a c c a a a a a a
a a c c a a a a a a
*/