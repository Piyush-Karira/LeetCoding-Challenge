/*
Time Complexity: 
	insert: O(K) where K is number of keys
	search:O(K) where K is number of keys

Space Complexity: 
	insert: O(K) where k is number of K worst case
	search: O(1)
*/

struct TrieNode {
    TrieNode* links[26];
    bool end;
    
    public:
        TrieNode(){
            end = false;
            memset(links, 0, sizeof(links));
        }
};

class Trie {
public:
    /** Initialize your data structure here. */
    
    TrieNode *root;
    Trie() {
        root = new TrieNode();
    }
    
    ~Trie(){
        clear(root);
    }

    void clear(TrieNode* root){
        for(int i=0;i<26;i++){
            if(root->links[i])   clear(root->links[i]);
        }
        delete root;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *node = root;
        
        for(char c:word){
            if(!node->links[c-'a'])
                node->links[c-'a'] = new TrieNode();
            node = node->links[c-'a'];
        }
        
        node->end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *node = root;
        
        for(char c:word){
            if(!node->links[c-'a']) 
                return false;
            node = node->links[c-'a'];
        }
        return node->end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *node = root;
        
        for(char c:prefix){
            if(!node->links[c-'a'])
                return false;
            node = node->links[c-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
