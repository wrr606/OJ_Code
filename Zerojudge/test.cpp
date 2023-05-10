#include <iostream>

using namespace std;

// 二元樹節點
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// 二元樹
class BinaryTree {
public:
    Node* root;

    BinaryTree() {
        root = nullptr;
    }

    // 插入節點
    void insert(int value) {
        Node* newNode = new Node(value);

        if (root == nullptr) {
            root = newNode;
        }
        else {
            Node* curr = root;
            while (true) {
                if (value < curr->data) {
                    if (curr->left == nullptr) {
                        curr->left = newNode;
                        break;
                    }
                    else {
                        curr = curr->left;
                    }
                }
                else {
                    if (curr->right == nullptr) {
                        curr->right = newNode;
                        break;
                    }
                    else {
                        curr = curr->right;
                    }
                }
            }
        }
    }

    // 遍歷二元樹
    void traverse(Node* node) {
        if (node != nullptr) {
            traverse(node->left);
            cout << node->data << " ";
            traverse(node->right);
        }
    }
};

int main() {
    BinaryTree tree;

    // 插入節點
    tree.insert(5);
    tree.insert(2);
    tree.insert(7);
    tree.insert(1);
    tree.insert(4);

    // 遍歷二元樹
    tree.traverse(tree.root);
    cout << endl;

    return 0;
}
