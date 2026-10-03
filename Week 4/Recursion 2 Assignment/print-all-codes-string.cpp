/***
 * Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to print the list of all possible codes that can be generated from the given string.
 * The order of codes are not important. Just print them in different lines.
 * Eg: "1123" => {aabc, kbc, alc, aaw, kw}
 ***/
/*
  Given the input as a string, print all its possible combinations. You do not need to return anything.
  */
#include <string.h>
using namespace std;

void printAllPossibleCodes(string input, string output) {
    if(input.length() == 0) {
        cout << output << '\n';
        return;
    }
    
    int n = input[0] - '0';
    char ch = (char) ('a' + n - 1);
    printAllPossibleCodes(input.substr(1), output + ch);
    
    if(input.length() >= 2) {
        int ch1 = input[0] - '0';
        int ch2 = input[1] - '0';
    	n = ch1 * 10 + ch2;
    	if(n <= 26) {
        	char ch = (char) ('a' + n - 1);
        	printAllPossibleCodes(input.substr(2), output + ch);
    	}
    }
}

void printAllPossibleCodes(string input) {
   printAllPossibleCodes(input, "");
}