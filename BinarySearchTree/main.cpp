#include <iostream>
#include <vector>
using namespace std;
struct Node{
    int val;
    Node *left = nullptr;
    Node *right = nullptr;
};
//二叉查找树的创建，查找,插入和删除节点
class BinarySearchTree {
public:
    BinarySearchTree();

    void insert(int value);
    Node* search(int value);
    void deleteNode(int value);
    Node* minNode();
    void midOrder();  //二叉搜索树的中序遍历输出即是有序输出
    void preOrder();
    void invert();
private:
    Node *root = nullptr;

    void midOrder_recursive(Node *node);
    void preOrder_recursive(Node *node);
    Node* invert_recursive(Node *node);
};


int main()
{
    BinarySearchTree tree;
    vector<int> vi = {6,3,4,5,2,1,7};
    for(auto it : vi) {
        tree.insert(it);
    }
    tree.midOrder();
    cout <<endl;
    cout << tree.search(1)->val << endl;
    cout << tree.search(6)->val << endl;
    cout << tree.search(7)->val << endl;
    if (tree.search(10)==nullptr)
        cout << "not include value 10" <<endl;

    cout << tree.minNode()->val << endl;
#if 0 //删除节点的测试
    tree.preOrder();
    cout <<endl;
    tree.deleteNode(7);
    tree.preOrder();

    cout <<endl;
    tree.deleteNode(3);
    tree.preOrder();

    cout <<endl;
    tree.deleteNode(4);
    tree.preOrder();

    cout <<endl;
    tree.deleteNode(6);
    tree.preOrder();
#endif

    tree.invert();
    tree.preOrder();
    cout << "Hello World!" << endl;
    return 0;
}

BinarySearchTree::BinarySearchTree()
{

}

void BinarySearchTree::insert(int value)
{
    if (root == nullptr) {
        root = new Node;
        root->val = value;
        return;
    }
    Node *node = root;
    while (node != nullptr) {
        if (value >= node->val){
            if ( node->right == nullptr ){
                node->right = new Node;
                node->right->val = value;
                return;
            }
            node = node->right;
        }
        else {
            if ( node->left == nullptr ){
                node->left = new Node;
                node->left->val = value;
                return;
            }
            node = node->left;
        }
    }
}

Node* BinarySearchTree::search(int value)
{
    Node *node = root;
    while (node != nullptr) {
        if (node->val == value)
            return node;
        else if(node->val < value){
            node = node->right;
        }
        else {
            node = node->left;
        }
    }
    return nullptr;
}

void BinarySearchTree::deleteNode(int value)
{

    Node *node = root;
    Node *parent = nullptr;

    while (node != nullptr && node->val != value) {
        parent = node;
        if (node->val < value)
            node = node->right;
        else
            node = node->left;
    }
    if (node == nullptr)
        return;

    if (node->left != nullptr && node->right != nullptr) { //如果要删除的节点2个子节点都不为空，则将此节点替换为右子树中最小的节点

        Node *min = node->right;
        Node *minParent = node;
        while (min->left != nullptr) {
            minParent = min;
            min = min->left;
        }
        node->val = min->val;

        node = min;              //需要删除的点变为右子树最小节点了
        parent = minParent;      //因为最小节点必然是一个叶子节点或者只有右子树的节点，所以可以和普通叶子节点一起处理
    }
    Node *child = nullptr;
    if (node->left ==nullptr && node->right == nullptr) {
        child = nullptr;
    }
    else if(node->left != nullptr){
        child = node->left;
    }
    else if(node->right != nullptr){
        child = node->right;
    }

    if (parent == nullptr) //删除的是根节点
        root = child;
    else if (parent->left == node)
        parent->left = child;
    else
        parent->right = child;

    delete node;
    node = nullptr;
}

Node *BinarySearchTree::minNode()
{
    Node* node = root;
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

void BinarySearchTree::midOrder()
{
    midOrder_recursive(root);
}

void BinarySearchTree::preOrder()
{
    preOrder_recursive(root);
}

void BinarySearchTree::invert()
{
    invert_recursive(root);
}

void BinarySearchTree::midOrder_recursive(Node *node)
{
    if (node == nullptr)
        return;

    midOrder_recursive(node->left);
    cout << node->val << ",";
    midOrder_recursive(node->right);
}

void BinarySearchTree::preOrder_recursive(Node *node)
{
    if (node == nullptr)
        return;

    cout << node->val << ",";
    preOrder_recursive(node->left);
    preOrder_recursive(node->right);
}

Node* BinarySearchTree::invert_recursive(Node *node)
{
    if (node == nullptr)
        return nullptr;

    Node *temp = node->left;
    node->left = invert_recursive(node->right);
    node->right = invert_recursive(temp);
    return node;
}



