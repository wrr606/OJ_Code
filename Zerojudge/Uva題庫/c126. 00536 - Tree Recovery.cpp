//c126. 00536 - Tree Recovery
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

class Node{
public:
    char data;
    Node* left;
    Node* right;
    Node(char value){
        data=value;
        right=nullptr;
        right=nullptr;
    }
};

class Tree{
public:
    Node* root;
    Tree(){
        root=nullptr;
    }

    Node* build_tree(vector<char>& preorder,vector<char>& inorder){
        if(preorder.empty()||inorder.empty()){
            return nullptr;
        }
        Node* point=new Node(preorder[0]);
        auto findit=find(all(inorder),preorder[0]);
        int length=findit-inorder.begin();
        vector<char> inorder_left(inorder.begin(),findit);
        vector<char> inorder_right(findit+1,inorder.end());
        vector<char> preorder_left(preorder.begin()+1,preorder.begin()+1+length);
        vector<char> preorder_right(preorder.begin()+1+length,preorder.end());
        point->left=build_tree(preorder_left,inorder_left);
        point->right=build_tree(preorder_right,inorder_right);
        return point;
    }

    void Postorder(Node* x){
        if(x){
            Postorder(x->left);
            Postorder(x->right);
            cout<<x->data;
        }
    }

    void del_tree(Node* x){
        if(x==nullptr)
            return;
        del_tree(x->left);
        del_tree(x->right);
        delete x;
    }
};

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    Tree tree;
    string pre,in;
    while(cin>>pre){
        cin>>in;
        vector<char> s1(all(pre)),s2(all(in));
        tree.root=tree.build_tree(s1,s2);
        tree.Postorder(tree.root);
        cout<<endl;
        tree.del_tree(tree.root);
    }
}