/*
---- The Approach We Have Taken To Implement This Problem ----
The approach we have taken to solve this problem is to store
the reverse of each of the words in the Trie. We then iterate
over the words and search that does the Trie contains the same
word or not.
It may happen that some parts of the word or a substring exist
in the Trie. We check for the remaining part of the string to
be a palindrome or not.
Vise versa of the above will also be true, that means, it may
happen that the word in the Trie may extend further over
different number of branches, hence we check all the branches
one by one to see if any of the branches make a palindrome.
*/
/*
---- Another Possible Solution Could Be ----
There's another way of solving this problem. It goes like this. First add
the reverse of every word in the trie. Then for every word, search it in
the trie. If you find it, then that means the word was a palindrome itself
and you can return true. If you don't find it, you need the length of the
part that you did find. For example, you're searching for "abcdd" in the
trie, you didn't find a match for "abcdd" but you found the word "abc" in
the trie. Finding "abc" in the trie means that the actual word was "cba"
since we inserted the reverse of every word in the list.
Now, you have the word "abcdd", you found the word "abc" in the trie. If you
can find whether the part of "abcdd" that comes after "abc", i.e. "dd" is a
palindrome, you can conclude that concatenating "abcdd" and "cba" will also
give a palindrome. So you can return true. If the part isn't a palindrome,
you move to check for the next word.
If you traverse through all words without finding a pair of words that
combine to form a palindrome or a word that's a palindrome by itself, then
you can return false.
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
    private boolean search(TrieNode root, String word) {
        if (word.length() == 0) {
            return root.isTerminating;
        }
        int childIndex = word.charAt(0) - 'a';
        TrieNode child = root.children[childIndex];
        if (child == null) {
            return false;
        }
        return search(child, word.substring(1));
    }
    public boolean search(String word) {
        return search(root, word);
    }
    private void print(TrieNode root, String word) {
        if (root == null) {
            return;
        }
        if (root.isTerminating) {
            System.out.println(word);
        }
        for (TrieNode child: root.children) {
            if (child == null) {
                continue;
            }
            String fwd = word + child.data;
            print(child, fwd);
        }
    }
    public void print() {
        print(this.root, "");
    }
    /*..................... Palindrome Pair................... */
    public boolean isPalindromePair(ArrayList < String > words) {
        for (String word: words) {
            this.add(reverseWord(word));
        }
        return isPalindromePair(this.root, words);
    }
    private static String reverseWord(String word) {
        String reverse = "";
        for (int i = word.length() - 1; i >= 0; i--) {
            reverse += word.charAt(i);
        }
        return reverse;
    }
    private boolean isPalindromePair(TrieNode root, ArrayList < String > words) {
        if (words == null || words.size() == 0) {
            return false;
        }
        for (String word: words) {
            if (doesPairExistFor(root, word, 0)) {
                return true;
            }
        }
        return false;
    }
    private boolean doesPairExistFor(TrieNode root, String word, int startIndex) {
        /* Since an empty string is always a palindrome, we return 'true' */
        if (word == "") {
            return true;
        }
        if (startIndex == word.length()) {
            if (root.isTerminating) {
                /*
                 * When there exists an exact match of the word we are
                 * searching for in the Trie, irrespective of the trie
                 * extends further in the same path.
                 *
                 */
                return true;
            }
            /*
             * When trie extends further, there doesnt exist an exact
             * match of the string we are looking for.
             * However, it may happen that any of the the branch
             * extending from root may form a palindrome.
             *
             * */
            return checkRemainingBranchesInTrie(root, "");
        }
        int charIndex = word.charAt(startIndex) - 'a';
        TrieNode correspondingChild = root.children[charIndex];
        if (correspondingChild == null) {
            /*
            * This means that, down the line in the characters that we are looking
            * for against the word in the trie, the character doesn't exist in the
            trie.
            * This character can be anywhere in the range [0 - (word length-1)]
            *
            * */
            if (root.isTerminating) {
                return checkWordForPalindrome(word.substring(startIndex));
            }
            return false;
        }
        return doesPairExistFor(correspondingChild, word, (startIndex + 1));
    }
    private boolean checkRemainingBranchesInTrie(TrieNode root, String word) {
        /*
         *
         * This function recursively explores all the branches from the root
         * while keeping a track of the characters in the 'word' and checks
         * each word whenever the terminating condition is true.
         *
         * If the word is a palindrome, we return true and stops exploring the
         * other branches. If it is otherwise, we keep on checking the remaining
         * branches.
         *
         * Once all the branches are explored, and we don't find any branch or
         * word that makes itself a palindrome we return false at last.
         *
         */
        if (root.isTerminating) {
            if (checkWordForPalindrome(word)) {
                return true;
            }
        }
        for (TrieNode childNode: root.children) {
            if (childNode == null) {
                continue;
            }
            String fwd = word + childNode.data;
            if (checkRemainingBranchesInTrie(childNode, fwd)) {
                return true;
            }
        }
        return false;
    }
    private static boolean checkWordForPalindrome(String word) {
        int startIndex = 0;
        int endIndex = word.length() - 1;
        while (startIndex < endIndex) {
            if (word.charAt(startIndex) != word.charAt(endIndex)) {
                return false;
            }
            startIndex += 1;
            endIndex -= 1;
        }
        return true;
    }
}