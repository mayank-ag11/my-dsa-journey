/***
 * Given a string S, print all the possible permutations of the input string.
 * The order of permutations is not important.
 * If original string contains duplicate characters, permutations will also be duplicates.
 ***/
#include <iostream>
#include <string>
using namespace std;

void printPermutations(string input, string output) {
    if(input.length() == 0) {
        cout << output << '\n';
        return;
    }
    
    int n = input.length();
    
    for(int i = 0; i < n; i++) {
        string smallinput = input.substr(0, i) + input.substr(i+1);
        printPermutations(smallinput, output + input[i]);
    }
}

void printPermutations(string input){
    printPermutations(input, "");
}