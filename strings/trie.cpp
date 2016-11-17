#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

struct Node {
    unordered_map<char, Node*> edges;
    bool isTerminal;

    Node(): isTerminal(false), edges() {}
    ~Node() {
        for (auto it = edges.begin(); it != edges.end(); ++it)
            delete it->second;
    }
};

void trie_insert(Node *trie, string s) {
    for (int i = 0; i < s.length(); ++i) {
        if (trie->edges.count(s[i]) == 0) {
            Node *newNode = new Node();
            trie->edges[s[i]] = newNode;
        }
        trie = trie->edges[s[i]];
    }
    trie->isTerminal = true;
}

bool trie_search(Node *trie, string s) {
    for (int i = 0; i < s.length(); ++i) {
        if (trie->edges.count(s[i]) == 0)
            return false;
        trie = trie->edges[s[i]];
    }
    return trie->isTerminal;
}

int main() {
    Node *trie = new Node();

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i){
        string s;
        cin >> s;

        trie_insert(trie, s);
    }

    while (true) {
        string find;
        cin >> find;
        cout << trie_search(trie, find) << endl;
9    }

}