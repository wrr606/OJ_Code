#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

struct Node
{
	bool have_value;
	Node* left;
	Node* right;
	int data;
	Node():have_value(0),left(NULL),right(NULL){}
};

Node* newnode(){
	return new Node();
}

Node* root;

void addnode(int v,string s){
	int n=s.size();
	Node* u=root;
	for(auto i:s){
		if(i=='L'){
			if(u->left==NULL)
				u->left=newnode();
			u=u->left;
		}
		else if(i=='R'){
			if(u->right==NULL)
				u->right=newnode();
			u=u->right;
		}
	}
}

int main(){
}