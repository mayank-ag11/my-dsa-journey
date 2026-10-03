/***
 * Given a list of n words and a pattern p that we want to search. Check if the pattern p is present the given words or not. Return true if the pattern is present and false otherwise.
 ***/
#include <string>
#include <vector>

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
    void addWordAndSuffixes(string word) {
        if(word.length() == 0)
            return;
        
        insertWord(word);
        addWordAndSuffixes(word.substr(1));
    }
    
    bool searchPattern(TrieNode *root, string pattern) {
        if(pattern.size() == 0) {
            return true;
        }
        
        int index = pattern[0] - 'a';
        TrieNode *child = root->children[index];
        if(child == NULL)
            return false;
        
        return searchPattern(child, pattern.substr(1));
    }

   public:
    bool patternMatching(vector<string> vect, string pattern) {
        for(int i = 0; i < vect.size(); i++) {
            addWordAndSuffixes(vect[i]);
        }
        
        return searchPattern(root, pattern);
    }
};

// Java Solution
/*
Time complexity: O(N * M)
Space complexity: O(N * M)
where N is the number of words in the Trie and M is the average word length
*/
import java.util.ArrayList;
class TrieNode {
    char data;
    boolean isTerminating;
    TrieNode children[];
    int childCount;
    public TrieNode(char data) {
        this.data = data;
        isTerminating = false;
        children = new TrieNode[26];
        childCount = 0;
    }
}
public class Trie {
    private TrieNode root;
    public int count;
    public Trie() {
        root = new TrieNode('\0');
    }
    public boolean search(String word) {
        return search(root, word);
    }
    private boolean search(TrieNode root, String word) {
        if (word.length() == 0) {
            return true;
        }
        int childIndex = word.charAt(0) - 'a';
        TrieNode child = root.children[childIndex];
        if (child == null) {
            return false;
        }
        return search(child, word.substring(1));
    }
    private void add(TrieNode root, String word) {
        if (word.length() == 0) {
            root.isTerminating = true;
            return;
        }
        int childIndex = word.charAt(0) - 'a';
        TrieNode child = root.children[childIndex];
        if (child == null) {
            child = new TrieNode(word.charAt(0));
            root.children[childIndex] = child;
            root.childCount++;
        }
        add(child, word.substring(1));
    }
    public void add(String word) {
        add(root, word);
    }
    public boolean patternMatching(ArrayList < String > vect, String pattern) {
        for (int i = 0; i < vect.size(); i++) {
            String word = vect.get(i);
            for (int j = 0; j < word.length(); j++) {
                add(word.substring(j));
            }
        }
        return search(pattern);
    }
}