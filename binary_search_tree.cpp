#include <iostream>
using namespace std;

struct Node {
    int key;
    Node *parent,
         *left,
         *right;

    Node (int _key, Node *_parent = NULL, Node *_left = NULL, Node *_right = NULL):
            key(_key), parent(_parent), left(_left), right(_right) {}

    ~Node() {
        delete left;
        delete right;
    }
};

class BST {
public:
    Node *root;

    BST(): root(NULL) {}

    Node *search(int key) {
        Node *cur = root;

        while (cur != NULL && key != cur->key) {
            if (key < cur->key)
                cur = cur->left;
            else
                cur = cur->right;
        }
        return cur;
    }

    Node *min(Node *cur) {
        while (cur->left != NULL)
            cur = cur->left;
        return cur;
    }

    Node *max(Node *cur) {
        while (cur->right != NULL)
            cur = cur->right;
        return cur;
    }

    Node *successor(Node *cur) {
        if (cur->right != NULL)
            return min(cur->right);

        Node *parent = cur->parent;
        while (parent != NULL && cur == parent->right) {
            cur = parent;
            parent = parent->parent;
        }

        return parent;
    }

    Node *predecessor(Node *cur) {
        if (cur->left != NULL)
            return max(cur->left);

        Node *parent = cur->parent;
        while (parent != NULL && cur == parent->left) {
            cur = parent;
            parent = parent->parent;
        }

        return parent;
    }

    Node *insert(int key) {
        Node *newNode = new Node(key),
             *parent = NULL,
             *place = root;

        while (place != NULL) {
            parent = place;
            if (newNode->key < place->key)
                place = place->left;
            else
                place = place->right;
        }

        newNode->parent = parent;

        if (parent == NULL)
            root = newNode;
        else if (newNode->key < parent->key)
            parent->left = newNode;
        else
            parent->right = newNode;

        return newNode;
    }

    void transplant(Node *subroot, Node *trans) {
        if (subroot->parent == NULL)
            root = trans;
        else if (subroot == subroot->parent->left)
            subroot->parent->left = trans;
        else
            subroot->parent->right = trans;

        if (trans != NULL)
            trans->parent= subroot->parent;
    }

    void remove(Node *toDelete) {
        if (toDelete->left == NULL)
            this->transplant(toDelete, toDelete->right);
        else if (toDelete->right == NULL)
            this->transplant(toDelete, toDelete->left);
        else {
            Node *suc = this->min(toDelete->right);
            if (suc->parent != toDelete) {
                // for suc substree to be correct
                this->transplant(suc, suc->right);
                suc->right = toDelete->right;
                suc->right->parent = suc;
            }
            this->transplant(toDelete, suc);
            suc->left = toDelete->left;
            suc->left->parent = suc;
        }
    }

    void print(Node *cur) {
        if (cur == NULL) return;

        print(cur->left);
        cout << cur->key << " ";
        print(cur->right);
    }

    ~BST() {delete root;}
};

int main() {
    BST tree;
    tree.print(tree.root);
    cout << endl;

    tree.insert(5);
    tree.insert(10);
    tree.insert(1);

    tree.print(tree.root);
    cout << endl;

    cout << tree.min(tree.root)->key << " "
         << tree.max(tree.root)->key << endl;

    Node *n7 = tree.insert(7);
    tree.insert(8);
    cout << tree.successor(n7)->key << " " << tree.predecessor(n7)->key << endl;

    tree.remove(tree.search(8));
    cout << tree.successor(n7)->key << endl;
}






