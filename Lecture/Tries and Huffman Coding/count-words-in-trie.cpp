/***
 * You are given the Trie class with following functions -
    1. insertWord
    2. removeWord
 * Now, you need to create one more function (named "countWords" ) which returns the number of words currently present in Trie in O(1) time complexity.
 ***/
class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }

        isTerminal = false;
    }
};

class Trie {
    TrieNode *root;

   public:
    Trie() { 
        root = new TrieNode('\0'); 
    }

    void insertWord(TrieNode *root, string word) {
        // Base case
        if (word.size() == 0) {
            root->isTerminal = true;
            return;
        }

        // Small calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        insertWord(child, word.substr(1));
    }

    void insertWord(string word) { 
        insertWord(root, word); 
    }

    void removeWord(TrieNode *root, string word) {
        // Base case
        if (word.size() == 0) {
            root->isTerminal = false;
            return;
        }

        // Small calculation
        TrieNode *child;
        int index = word[0] - 'a';

        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            return;
        }

        removeWord(child, word.substr(1));

        // Remove child Node if it is useless
        if (child->isTerminal == false) {
            for (int i = 0; i < 26; i++) {
                if (child->children[i] != NULL) {
                    return;
                }
            }

            delete child;
            root->children[index] = NULL;
        }
    }

    void removeWord(string word) { 
        removeWord(root, word); 
    }
    
    // Count Words in Trie
    int countWords(TrieNode *root) {
        int count = 0;
        
        for(int i = 0; i < 26; i++) {
            TrieNode *child = root->children[i];
            if(child != NULL) {
                count += countWords(child);
                
                if(child->isTerminal == true)
                count += 1;
            }
        }
        
        return count;
    }
    
    int countWords() {
        return countWords(root);
    }
};