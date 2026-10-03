/***
 * Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to return the list of all possible codes that can be generated from the given string.
 * The order of codes are not important. And input string does not contain 0s.
 * Eg: "1123" => {aabc, kbc, alc, aaw, kw}
 ***/
/*
    You are given the input text and output string array. Find all possible codes and store in the output string array. Don’t print the codes.
    Also, return the number of codes return to the output string. You do not need to print anything.
    */

// Coding Ninjas Solution
#include <string.h>
using namespace std;
int getCodes(string input, string output[]) {
    if(input[0] == '\0'){
        output[0] = "";
        return 1;
    }
    int first = input[0] - 48;
    char firstChar = first + 'a' - 1;
    char secondChar = '\0';
    string smallOutput1[500];
    string smallOutput2[500];
    int size1 = getCodes(input.substr(1), smallOutput1);
    int size2 = 0;
    if(input[1] != '\0'){
        int second = first * 10 + input[1] - 48;
        if(second >= 10 && second <= 26){
            secondChar = second + 'a' - 1;
            size2 = getCodes(input.substr(2), smallOutput2);
        }
    }
    int k = 0;
    for(int i = 0; i < size1; i++){
        output[k] = firstChar + smallOutput1[i];
        k++;
    }
    for(int i = 0; i < size2; i++){
        output[k] = secondChar + smallOutput2[i];
        k++;
    }
    return k;
}

// Mine
#include <string.h>
using namespace std;

/*int stringToInt(string str) {
    int i = 0, n = 0;
    while(str[i] != '\0') {
        n = n * 10 + (str[i] - '0');
        i++;
    }
    return n;
}
inline char getAlpha(int n) {
    return 'a' + n - 1;
} */

int getCodes(string input, string output[10000]) {
    if(input.length() == 0) {
        output[0] = "";
        return 1;
    }
    /*if(input.length() == 1) {
        int n = input[0] - '0';
        output[0] += (char) ('a' + n - 1);
        return 1;
    }*/
    
    string op1[10000];
    int n1 = getCodes(input.substr(1), op1);
    int k = 0;
    int n = input[0] - '0';
    char ch = (char) ('a' + n - 1);
    for(int i=0; i<n1; i++)
        output[k++] = ch + op1[i];
    
    if(input.length() >= 2) {
        int ch1 = input[0] - '0';
        int ch2 = input[1] - '0';
    	n = ch1 * 10 + ch2;
    	if(n <= 26) {
        	char ch = (char) ('a' + n - 1);
        	string op2[10000];
        	int n2 = getCodes(input.substr(2), op2);
        	for(int i=0; i<n2; i++)
            	output[k++] = ch + op2[i];
    	}
    }
    
    return k;
}