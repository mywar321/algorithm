#include <iostream>
#include <queue>
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
    void levelOrder();
private:
    Node *root;

    void createNode(Node* &node);
    void deleteNode(Node* &node);
    int height_recursive(Node *node);
    void preOrder_recursive(Node *node);
    void levelOrder_recursive(queue<Node *> &level_queue);
};


int main()
{
    BinaryTree tree;
    cout <<tree.height() << endl;
    tree.preOrder();
    tree.levelOrder();
    cout << "Hello World!" << endl;
    return 0;
}

BinaryTree::BinaryTree():
    root(nullptr)
{
    createNode(root);
}

BinaryTree::~BinaryTree()
{
    deleteNode(root);
}

int BinaryTree::height()
{
    return height_recursive(root);
}

void BinaryTree::preOrder()
{
    preOrder_recursive(root);
}

void BinaryTree::levelOrder()
{
    queue<Node *> level_queue;
    level_queue.push(root);
    levelOrder_recursive(level_queue);
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

void BinaryTree::deleteNode(Node* &node)
{
    if (node == nullptr)
        return;
    deleteNode(node->left);
    deleteNode(node->right);
    delete node;
    node = nullptr;
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

void BinaryTree::levelOrder_recursive(queue<Node *> &level_queue)
{
    if (level_queue.empty())
        return;
    Node *node = level_queue.front();
    level_queue.pop();
    cout << node->val << ",";
    if (node->left != nullptr)
        level_queue.push(node->left);
    if (node->right != nullptr)
        level_queue.push(node->right);
    levelOrder_recursive(level_queue);
}
