// https://leetcode.com/problems/implement-trie-prefix-tree/

/*
Count the number of words with given prefix using Trie
*/

class Trie {
    struct TrieNode {
        char val;
        int count;
        int endsHere;
        TrieNode *child[26];
    };
    
    TrieNode *getNode(char value) {
        TrieNode *newnode = new TrieNode;
        newnode->val = value;
        newnode->count = newnode->endsHere = 0;
        for(int i=0;i<26;++i)
            newnode->child[i] = NULL;
        return newnode;
    }
    
    TrieNode *root;
    
public:
    /** Initialize your data structure here. */
    Trie() {
        root = getNode('/');
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *curr = root;
        int index;
        for(char ch: word) {
            index = ch - 'a';
            if(!curr->child[index]) {
                curr->child[index] = getNode(ch);
            }
            curr->child[index]->count++;
            curr = curr->child[index];
        }
        curr->endsHere++;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *curr = root;
        int index;
        for(char ch: word) {
            index = ch - 'a';
            if(!curr->child[index]) {
                return false;
            }
            curr = curr->child[index];
        }
        return (curr->endsHere > 0);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *curr = root;
        int index;
        for(char ch: prefix) {
            index = ch - 'a';
            if(!curr->child[index]){
                return false;
            }
            curr = curr->child[index];
        }
        return (curr->count > 0);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
