class TrieNode {
public:
    TrieNode *children[26];
    bool endw; // end of word

    TrieNode() {
        for (int i = 0; i < 26; ++i) children[i] = nullptr;
        endw = false;
    }
};

class PrefixTree {
private:
    TrieNode *root;
public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *cur = root;
        for (const char c : word) {
            const int idx = c - 'a';
            if (cur->children[idx] == nullptr)
                cur->children[idx] = new TrieNode();
            cur = cur->children[idx];
        }
        cur->endw = true;
    }
    
    bool search(string word) {
        TrieNode *cur = root;
        for (const char c : word) {
            const int idx = c - 'a';
            if (cur->children[idx] == nullptr)
                return false;
            cur = cur->children[idx];
        }
        return cur->endw;
    }
    
    bool startsWith(string prefix) {
        TrieNode *cur = root;
        for (const char c : prefix) {
            const int idx = c - 'a';
            if (cur->children[idx] == nullptr)
                return false;
            cur = cur->children[idx];
        }
        return true;
    }
};
