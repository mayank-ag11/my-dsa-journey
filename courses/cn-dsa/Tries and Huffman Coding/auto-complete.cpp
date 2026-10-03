/***
 * Given n number of words and an incomplete word w. You need to auto-complete that word w.
 * That means, find and print all the possible words which can be formed using the incomplete word w.
 * Note : Order of words does not matter.
 * TestCase:
 * ["do", "dont", "no", "not", "note", "notes", "den"], w = "no"
    =>  no
        not
        note
        notes
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
    int count;

    Trie() {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool insertWord(TrieNode *root, string word) {
        // Base case
        if (word.size() == 0) {
            if (!root->isTerminal) {
                root->isTerminal = true;
                return true;
            } else {
                return false;
            }
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
        return insertWord(child, word.substr(1));
    }

    void insertWord(string word) {
        if (insertWord(root, word)) {
            this->count++;
        }
    }

   private:
    void printAllPossibleRecommendations(TrieNode *root, string word) {
        if(root->isTerminal) {
            cout << word << '\n';
        }

        for(int i = 0; i < 26; i++) {
            TrieNode *child = root->children[i];
            if(child != NULL)
                printAllPossibleRecommendations(child, word + child->data);
        }
    }

    void autoComplete(TrieNode *root, string pattern, string word) {
        if(pattern.size() == 0) {
            printAllPossibleRecommendations(root, word);
            return;
        }

        int index = pattern[0] - 'a';
        TrieNode *child = root->children[index];
        if(child == NULL)
            return;
        
        autoComplete(child, pattern.substr(1), word + pattern[0]);
    }

   public:
    void autoComplete(vector<string> input, string pattern) {
        for(string word : input) {
            insertWord(word);
        }

        autoComplete(root, pattern, "");
    }
};