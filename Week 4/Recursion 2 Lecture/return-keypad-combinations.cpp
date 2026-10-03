/***
 * Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
 * Return empty string for numbers 0 and 1.
 ***/
#include <string>
using namespace std;

int keypad(int n, string output[], string keypad_codes[]) {
    if(n == 0) {
        output[0] = "";
        return 1;
    }
    
    int smallOutputSize = keypad(n/10, output, keypad_codes);
    int num = n % 10;
    
    string prevOutput[smallOutputSize];
    for(int i=0; i<smallOutputSize; i++)
        prevOutput[i] = output[i];
    
    string keycode = keypad_codes[num];
    int k = 0;
    for(int i=0; i<smallOutputSize; i++) {
        for(int j=0; j<keycode.length(); j++) {
            output[k++] = prevOutput[i] + keycode[j];
        }
    }
    return k;
}

int keypad(int num, string output[]){
    if(num < 2)
        return 0;
    string keypad_codes[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    return keypad(num, output, keypad_codes);
}