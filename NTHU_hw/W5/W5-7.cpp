#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define all(x) x.begin(),x.end() 
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vector<int> > vvi;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

//註解部分為修改為 max 要改動的地方
class Node {
public:
    Node* left;
    Node* right;
    int l;
    int r;
    int mid;
    int v;
    int add;
    Node(int l, int r) {
        this->l = l;
        this->r = r;
        this->mid = (l + r) >> 1;
        this->left = this->right = nullptr;
        v = add = 0;
    }
};
class SegmentTree {
private:
    Node* root;
 
public:
    SegmentTree() {
        root = new Node(1, 1e9);
    }
 
    void modify(int l, int r, int v) {
        modify(l, r, v, root);
    }
 
    void modify(int l, int r,int v, Node* node) {
        if(node->l>r||node->r<l) return;
 
        if (node->l >= l && node->r <= r)
        {
            node->v += v;//node->v += v; 
            node->add += v;
            return;
        }
        pushdown(node);
        modify(l, r, v, node->left);
        modify(l, r, v, node->right);
        merge(node);
    }
 
    int query(int l, int r) {
        return query(l, r, root);
    }
 
    int query(int l, int r, Node* node) {
        if(node->l>r||node->r<l) return INT_MIN;//return INT_MIN;
        if (node->l >= l && node-> r <= r) return node->v;
        pushdown(node);

        return max(query(l, r, node->left), query(l, r, node->right));//取max
    }
 
    void merge(Node* node) {
        node->v = max(node->left->v, node->right->v);//取max，就改到這
    }
 
    void pushdown(Node* node) {
        if (!node->left) node->left = new Node(node->l, node->mid);
        if (!node->right) node->right = new Node(node->mid + 1, node->r);
        if (node->add)
        {
            Node* left = node->left;
            Node* right = node->right;
            left->v += node->add;
            left->add += node->add;
 
            right->v += node->add;
            right->add += node->add;
            node->add = 0;
        }
    }
};


int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    SegmentTree st;
    int n, k, x;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>x;
        st.modify(i, i, x);
    }
    for(int i=1;i<=n;i++){
        x = st.query(i, min(n, i + k - 1));
        if(i + k - 1 > n)
            x = max(x, st.query(1, i + k - 1 - n));
        cout<<x<<" ";
    }
}