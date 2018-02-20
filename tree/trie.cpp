// https://www.interviewbit.com/problems/shortest-unique-prefix/

class Node {
public:
    Node(): alphSize(26), childrens(vector<Node*>(alphSize, nullptr)), 
            wordEnd(false), wordsCt(0) {}

    bool has(char c) {
        return childrens[c] != nullptr;
    }
    
    bool add(int i) {
        childrens[i] = new Node();
    }
    
    Node* child(int i) {
        return childrens[i];
    }
    
    bool wordEnd;
    int wordsCt;

private:
    int alphSize;
    vector<Node*> childrens;
    
};

class Trie {
public:
    Trie(): head(new Node()) {}

    void insert(string &word) {
        Node *tmphead = head;
        
        for (int i = 0; i < word.size(); ++i) {
            tmphead->wordsCt++;
            
            int next = word[i] - 'a';
            
            if (!tmphead->has(next)) {
                tmphead->add(next);
            }
            
            tmphead = tmphead->child(next);
        }
        
        tmphead->wordEnd = true;
    }
    
    bool has(string &word) {
        Node *tmphead = head;
        
        for (int i = 0; i < word.size(); ++i) {
            int next = word[i] - 'a';
            
            if (!tmphead->has(next)) {
                return false;
            }
            
            tmphead = tmphead->child(next);
        }
        
        return tmphead->wordEnd;
    }
    
    string shrink(string &word) {
        Node *tmphead = head;
        string shrank = "";
        
        for (int i = 0; i < word.size(); ++i) {
            int next = word[i] - 'a';
            tmphead = tmphead->child(next);
            shrank += word[i];
            
            if (tmphead->wordsCt == 1) {
                return shrank;
            }
        }
    }

private:
    Node *head;
};

Trie build_trie(vector<string> words) {
    Trie trie;
    
    for (int i = 0; i < words.size(); ++i) {
        trie.insert(words[i]);
    }
    
    return trie;
}

vector<string> Solution::prefix(vector<string> &A) {
    Trie trie = build_trie(A);
    
    vector<string> res;
    for (int i = 0; i < A.size(); ++i) {
        res.push_back(trie.shrink(A[i]));
    }
    
    return res;
}

