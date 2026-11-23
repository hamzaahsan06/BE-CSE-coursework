#include <iostream>
using namespace std;

class Node
{
public:
    char data;
    Node *left;
    Node *right;
    Node(char value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};
class BinaryTree
{
private:
    Node *root;
    void clearHelper(Node *p)
    {
        if (p == nullptr)
            return;
        clearHelper(p->left);  // depth traverse in left subtree
        clearHelper(p->right); // depth traverse in right subtree
        delete p;              // delete this node after its children are gone
    }

public:
    BinaryTree()
    {
        root = nullptr;
    }
    void setRoot(Node *n) { root = n; }

    void clearTree()
    {
        clearHelper(root); // free all nodes
        root = nullptr;
        cout << "Tree cleared." << endl;
    }
};
int main()
{
    BinaryTree t;

    // Test 1: empty tree
    t.clearTree();

    // Test 2: single node
    Node *r = new Node('A');
    t.setRoot(r);
    t.clearTree();

    // Test 3: small tree
    r = new Node('A');
    r->left = new Node('B');
    r->right = new Node('C');
    r->left->left = new Node('D');
    t.setRoot(r);
    t.clearTree();

    return 0;
}