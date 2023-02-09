// Also known as Prefix tree

// Applications of Tries: Autocomplete, Spell checker,
//                        IP routing (Longest prefix matching),
//                        T9 predictive text, Solving word games .....

// Time : O(m), m is the lenght of the word
// Space: O(m), [Insertion]
// Space: O(1), [Search, starts with]

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool word_ = false;
};

class Trie {
public:
    // starting of the tree
    TrieNode root;
    
    void insert(string word) {
        TrieNode *curr = &root;
        for (char c: word) {
            // if c is not a children, add c 
            if (curr->children.count(c) == 0) {
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }
        // end of the word
        curr->word_ = true;
    }

    bool search(string word) {
        TrieNode *curr = &root;

        for (char c: word) {
            if (curr->children.count(c) == 0) {
                return false;
            }
            curr = curr->children[c];
        }
        // curr->word returns true if we reach the end of the word
        return curr->word_;
    }

    bool startsWith(string prefix) {
        TrieNode *curr = &root;
        for (char c: prefix) {
            if (curr->children.count(c) == 0) {
                return false;
            }
            curr = curr->children[c];
        }
        // there exist a word with given prefix
        return true;
    }
};