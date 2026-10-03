/***
 * Given a string S, find and return all the possible permutations of the input string.
 * The order of permutations is not important.
 * If original string contains duplicate characters, permutations will also be duplicates.
 ***/
#include <string>
using namespace std;

int returnPermutations(string input, string output[]){
    if(input.length() == 0)
        return 0;
    if(input.length() == 1) {
        output[0] = input;
        return 1;
    }
    
    string smalloutput[10000];
    int n = returnPermutations(input.substr(1), smalloutput);
    
    int l = input.length(), k = 0;
    for(int i = 0; i < n; i++) {
        string str = smalloutput[i];
        for(int j = 0; j < l; j++) {
            output[k] = str.substr(0, j)
            		  + input[0]
            		  + str.substr(j);
            k++;
        }
    }
    
    return n * l;
}