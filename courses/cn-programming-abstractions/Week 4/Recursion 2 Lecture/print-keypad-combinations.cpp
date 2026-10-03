// Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.
#include <iostream>
#include <string>
using namespace std;

void printKeypad(int n, string output, string keypad[]) {
    if(n == 0) {
        cout << output << '\n';
        return;
    }
    
    int num = n % 10;
    string keycode = keypad[num];
    
    for(int i=0; i<keycode.length(); i++) {
        printKeypad(n/10, keycode[i] + output, keypad);
    }
}

void printKeypad(int num){
    string keypad_codes[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    printKeypad(num, "", keypad_codes);
}