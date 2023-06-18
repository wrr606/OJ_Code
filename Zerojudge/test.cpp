#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

class Node{
public:
    Node* right;
    Node* left;
    int value;
    Node(){
        value=-1;
        left=nullptr;
        right=nullptr;
    }
};

class Tree{
public:
    Node* root;
    Tree(){
        root=nullptr;
    }

    void insert(int data,Node* cur){
        //cout<<data<<endl;
        if(root->value==-1){
            root->value=data;
        }
        if(data>cur->value){
            if(cur->right==nullptr){
                cur->right=new Node();
                cur=cur->right;
                cur->value=data;
            }
            else{
                cur=cur->right;
                insert(data,cur);
            }
        }
        else if(data<cur->value){
            if(data<cur->value){
                cur->left=new Node();
                cur=cur->left;
                cur->value=data;
            }
            else{
                cur=cur->left;
                insert(data,cur);
            }
        }
    }

    void BFS(){
        queue<Node*> que;
        Node* cur=root;
        que.push(cur);
        while(!que.empty()){
            if(que.front()==nullptr){
                que.pop();
                continue;
            }
            cout<<que.front()->value<<" ";
            que.push(que.front()->left);
            que.push(que.front()->right);
            que.pop();
        }
    }
};


int main(){
    //ios::sync_with_stdio(0),cin.tie(0);
    Tree x;
    x.root=new Node();
    for(int i=0;i<=10;i++){
        x.insert(i,x.root);
    }
    for(int i=50;i<=100;i+=3){
        x.insert(i,x.root);
    }
    for(int i=10;i<=50;i+=2){
        x.insert(i,x.root);
    }
    x.BFS();
    cout<<"END\n";
}