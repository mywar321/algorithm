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
private:
    Node *root = nullptr;

    void midOrder_recursive(Node *node);

};


int main()
{
    BinarySearchTree tree;
    vector<int> vi = {6,3,4,5,2,1,7};
    for(auto it : vi) {
        tree.insert(it);
    }
    tree.midOrder();

    cout << tree.search(1)->val << endl;
    cout << tree.search(6)->val << endl;
    cout << tree.search(7)->val << endl;
    if (tree.search(10)==nullptr)
        cout << "not include value 10" <<endl;

    cout << tree.minNode()->val << endl;
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

//    Node *node = root;
//    Node *parent = nullptr;

//    while (node != nullptr) {

//        if (node->val == value) {
//            if (node->left == nullptr && node->right==nullptr) {

//                Node *toDelete = (parent->left->val == node->val) ? parent->left : parent->right;
//                delete toDelete;
//                toDelete = nullptr;
//            }
//        }
//        else if(node->val < value){
//            parent = node;
//            node = node->right;
//        }
//        else {
//            parent = node;
//            node = node->left;
//        }
//    }

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

void BinarySearchTree::midOrder_recursive(Node *node)
{
    if (node == nullptr)
        return;

    midOrder_recursive(node->left);
    cout << node->val << ",";
    midOrder_recursive(node->right);
}



