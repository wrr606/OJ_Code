#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	while(cin>>n){
		map <char, vector<int> > mp;
	    mp['c'] = {0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1};
	    mp['d'] = {0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0};
	    mp['e'] = {0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0};
	    mp['f'] = {0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0};
	    mp['g'] = {0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0};
	    mp['a'] = {0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0};
	    mp['b'] = {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0};
	    mp['C'] = {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0};
	    mp['D'] = {0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0};
	    mp['E'] = {0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0};
	    mp['F'] = {0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0};
	    mp['G'] = {0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0};
	    mp['A'] = {0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0};
	    mp['B'] = {0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0};
		string song;
		getline(cin,song);
		for(int o=0;o<n;o++){
			vector<int> finger={0,0,0,0,0,0,0,0,0,0,0};
			vector<bool> finger_bool={0,0,0,0,0,0,0,0,0,0,0};
			getline(cin,song);
			if(song==""){
				for(int i=1;i<11;i++){
					cout<<finger[i]<<" ";
				}
				cout<<endl;
				continue;
			}
			for(auto i:song){
				for(int j=1;j<11;j++){
					if(!finger_bool[j]&&mp[i][j]){
						finger[j]++;
						finger_bool[j]=1;
					}
					else if(finger_bool[j]&&!mp[i][j]){
						finger_bool[j]=0;
					}
				}
			}
			for(int i=1;i<11;i++){
					cout<<finger[i]<<" ";
			}
			cout<<endl;
		}
	}
}