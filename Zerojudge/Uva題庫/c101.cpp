//c101. 00122 - Trees on the level
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

void split(string s,int& a,string& b){
    int find_index=s.find(',');
    a=stoi(s.substr(0,find_index));
    b=s.substr(find_index+1);
}

bool failed=0;

class Node{
public:
    int data;
    bool have_value;
    Node* left;
    Node* right;
    Node(){
        have_value=0;
        data=-1;
        left=nullptr;
        right=nullptr;
    }
};

class BinaryTree{
public:
    Node* root;
    BinaryTree(){
        root=nullptr;
    }

    void insert(int value,string s){
        Node* cerrent=root;
        for(int i=0;i<s.size();i++){
            if(s[i]=='L'){
                if(cerrent->left==nullptr)
                    cerrent->left=new Node();
                cerrent=cerrent->left;
            }
            else if(s[i]=='R'){
                if(cerrent->right==nullptr)
                    cerrent->right=new Node();
                cerrent=cerrent->right;
            }
        }
        if(cerrent->have_value)
            failed=1;
        cerrent->have_value=1;
        cerrent->data=value;
    }

    bool BFS(vector<int>& ans){
        deque<Node*> que;
        que.push_back(root);
        ans.clear();
        while(!que.empty()){
            auto que_first=que.front();
            if(!que_first->have_value)
                return 0;
            ans.push_back(que_first->data);
            if(que_first->left!=nullptr)
                que.push_back(que_first->left);
            if(que_first->right!=nullptr)
                que.push_back(que_first->right);
            que.pop_front();
        }
        return 1;
    }

    void remove_tree(Node* x){
        if(x==nullptr)
            return;
        remove_tree(x->left);
        remove_tree(x->right);
        delete x;
    }
};

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    string s,rout;
    int num;
    BinaryTree tree;
    tree.root=new Node();
    vector<int> ans;
    while(cin>>s){
        if(s=="()"){
            if(failed){
            cout<<"not complete";
            }
            else if(tree.BFS(ans)){
                for(int i=0;i<ans.size()-1;i++)
                    cout<<ans[i]<<" ";
                cout<<ans[ans.size()-1];
            }
            else
                cout<<"not complete";
            cout<<endl;
            tree.remove_tree(tree.root);
            tree.root=new Node();
            failed=0;
            continue;
        }
        s=s.substr(1,s.size()-2);
        split(s,num,rout);
        tree.insert(num,rout);
    }
}