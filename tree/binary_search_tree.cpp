#include <iostream>
using namespace std;

struct Node {
    int key;
    Node *left,
         *right;

    Node (int _key, Node *_left = NULL, Node *_right = NULL):
            key(_key), left(_left), right(_right) {}

    ~Node() {
        delete left;
        delete right;
    }
};

class BST {
public:
    Node *root;

    BST(): root(NULL) {}

    Node **search(Node **cur, int key) {
        while (*cur != NULL && key != (*cur)->key) {
            if (key < (*cur)->key)
                cur = &((*cur)->left);
            else
                cur = &((*cur)->right);
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

    Node *insert(int key) {
        Node **toInsert = search(&root, key);
        if (*toInsert == NULL)
            *toInsert = new Node(key);
        else
            (*toInsert)->key = key;

        return *toInsert;
    }

    void remove(Node *startFrom, int key) {
        Node **toDelete = search(&startFrom, key);

        if (*toDelete == NULL)
            return;

        if ((*toDelete)->left != NULL && (*toDelete)->right != NULL) {
            int newKey = min((*toDelete)->right)->key;
            remove(*toDelete, newKey);
            (*toDelete)->key = newKey;
        } else {
            Node *tmpNode = *toDelete;

            if ((*toDelete)->left == NULL)
                *toDelete = (*toDelete)->right;
            else
                *toDelete = (*toDelete)->left;

            if (tmpNode == root)
                root = NULL;

            tmpNode->right = tmpNode->left = NULL;
            delete tmpNode;
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

    tree.insert(5);
    tree.insert(2);
    tree.insert(10);
    tree.insert(9);
    tree.insert(11);

    tree.print(tree.root);
    cout << endl;

    tree.remove(tree.root, 10);
    tree.remove(tree.root, 11);
    tree.remove(tree.root, 9);
    tree.remove(tree.root, 2);
    tree.remove(tree.root, 5);

    tree.print(tree.root);
    cout << endl;
}






