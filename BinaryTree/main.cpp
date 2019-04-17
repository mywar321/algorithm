#include <iostream>

using namespace std;

struct Node{
    int val;
    Node *left;
    Node *right;

};

class BinaryTree{
public:
    BinaryTree();
    ~BinaryTree();

    int height();
    void preOrder();
private:
    Node *root;

    void createNode(Node* &node);
    int height_recursive(Node *node);
    void preOrder_recursive(Node *node);
};


int main()
{
    BinaryTree tree;
    cout <<tree.height() << endl;
    tree.preOrder();
    cout << "Hello World!" << endl;
    return 0;
}

BinaryTree::BinaryTree()
{
    createNode(root);
}

BinaryTree::~BinaryTree()
{

}

int BinaryTree::height()
{
    return height_recursive(root);
}

void BinaryTree::preOrder()
{
    preOrder_recursive(root);
}

void BinaryTree::createNode(Node* &node)
{
    int input = 0;
    //cout << "enter -1 to create null node:";
    cin >> input;
    if (input ==-1) {
        node = nullptr;
    }
    else {
        node = new Node;
        node->val = input;
        cout << "enter left node value:";
        createNode(node->left);
        cout << "enter right node value:";
        createNode(node->right);
    }


}

int BinaryTree::height_recursive(Node *node)
{
    if(node ==nullptr)
        return 0;

    int left_h = height_recursive(node->left);
    int right_h = height_recursive(node->right);
    return (left_h > right_h ? left_h : right_h)+1;
}

void BinaryTree::preOrder_recursive(Node *node)
{
    if (node == nullptr) {
        return;
    }
    cout << node->val << ",";
    preOrder_recursive(node->left);
    preOrder_recursive(node->right);
}
