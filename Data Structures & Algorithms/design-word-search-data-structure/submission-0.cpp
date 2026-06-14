class TrieNode {
public:
    TrieNode *children[26];
    bool endw; // end of word

    TrieNode() {
        for (int i = 0; i < 26; ++i) children[i] = nullptr;
        endw = false;
    }
};

class WordDictionary {
private:
    TrieNode *root;
public:
    WordDictionary() {
        this->root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode *cur = this->root;
        for (const char c : word) {
            if (cur->children[c - 'a'] == nullptr)
                cur->children[c - 'a'] = new TrieNode();
            cur = cur->children[c - 'a'];
        }
        cur->endw = true;
    }
    
    bool search(string word) {
        return dfsSearch(root, 0, word);
    }

    bool dfsSearch(TrieNode *cur, const int idx, const string& word) {
        if (idx == word.size()) return cur->endw ? true : false;

        if (word[idx] == '.') {
            for (int i = 0; i < 26; ++i) {
                if (cur->children[i] != nullptr
                    && dfsSearch(cur->children[i], idx + 1, word)
                ) return true;
            }
            return false;
        }

        const int alphabet = word[idx] - 'a';
        if (cur->children[alphabet] == nullptr) return false;
        return dfsSearch(cur->children[alphabet], idx + 1, word);
    }
};
