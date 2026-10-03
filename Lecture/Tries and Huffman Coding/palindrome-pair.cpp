/***
 * Given 'n' number of words, you need to find if there exist any two words which can be joined to make a palindrome or any word, which itself is a palindrome.
 * TestCases:
 * ["abc", "def", "ghi", "cba"] -> True
 * ["abc", "def"] -> False
 * ["abc", "ddcba"] -> True
 * ["abc", "mcba"] -> True
 * ["abcm", "cba"] -> True
 ***/
class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;
    int childCount;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
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

    bool add(TrieNode *root, string word) {
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
            root->childCount++;
        }

        // Recursive call
        return add(child, word.substr(1));
    }

    void add(string word) {
        if (add(root, word)) {
            this->count++;
        }
    }

    /*..................... Palindrome Pair................... */

   private:
    bool checkWordForPalindrome(string word) {
        int l = 0;
        int r = word.length() - 1;
        while(l < r) {
            if(word[l] != word[r])
                return false;
            l++;
            r--;
        }
        return true;
    }

    bool checkRemainingBranchesInTrie(TrieNode *root, string word) {
        if(root->isTerminal) {
            if(checkWordForPalindrome(word))
                return true;
        }

        // for each loop requires defining a begin() and an end()
        // https://users.cs.northwestern.edu/~riesbeck/programming/c++/stl-iterator-define.html
        // for(TrieNode *child : root->children)

        for(int i = 0; i < 26; i++) {
            TrieNode *child = root->children[i];
            if(child == NULL)
                continue;
            string fwd = word + child->data;
            if(checkRemainingBranchesInTrie(child, fwd))
                return true;
        }
        return false;
    }

    bool doesPairExistFor(TrieNode *root, string word) {
        if(word.size() == 0) {
            if(root->isTerminal)
                return true;
            return checkRemainingBranchesInTrie(root, "");
        }

        int index = word[0] - 'a';
        TrieNode *child = root->children[index];

        if(child == NULL) {
            // for cases like ["abcm", "cba"]
            if(root->isTerminal) {
                return checkWordForPalindrome(word.substr(1));
            }
            return false;
        }

        return doesPairExistFor(child, word.substr(1));
    }

    bool isPalindromePair(TrieNode *root, vector<string> words) {
        for(string word : words) {
            if(word == "" or doesPairExistFor(root, word))
                return true;
        }

        return false;
    }

    string reverseWord(string word) {
        string rev = "";
        for(int i = word.length() - 1; i >= 0; i--)
            rev += word[i];
        return rev;
    }

   public:
    bool isPalindromePair(vector<string> words) {
        if(words.size() == 0)
            return false;
        
        for(int i = 0; i < words.size(); i++) {
            add(reverseWord(words[i]));
        }
        
        return isPalindromePair(this->root, words);
    }

    /*
    // This doesn't work for ["abc", "mcba"]
    bool isPalindromePair(vector<string> words) {
        for(int i = 0; i < words.size(); i++) {
            add(words[i]);
            reverse(words[i].begin(), words[i].end());
        }
        
        for(int i = 0; i < words.size(); i++) {
            if(add(root, words[i]) == false)
                return true;
        }
        
        return false;
    }
    */
};