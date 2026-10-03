/***
 * Suppose you have a string, S, made up of only 'a's and 'b's. Write a recursive function that checks if the string was generated using the following rules:
 * a. The string begins with an 'a'
   b. Each 'a' is followed by nothing or an 'a' or "bb"
   c. Each "bb" is followed by nothing or an 'a'
 * If all the rules are followed by the given string, return true otherwise return false.
 ***/
#include<cstring>
using namespace std;

bool checkAB(char input[], string prev) {
    if(input[0] == '\0')
        return true;
    
    if(prev == "a") {
        if(input[0] == 'a')
            return checkAB(input+1, "a");
        else if(input[0] == 'b' && input[1] == 'b')
            return checkAB(input+2, "bb");
        return false;
    }
    else if(prev == "bb") {
        if(input[0] == 'a')
            return checkAB(input+1, "a");
        return false;
    }
    return false;
}
bool checkAB(char input[]) {
    if(input[0] != 'a')
        return false;
    return checkAB(input+1, "a");
}