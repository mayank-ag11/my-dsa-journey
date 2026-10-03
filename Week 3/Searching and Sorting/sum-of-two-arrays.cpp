/***
 * Two random integer arrays/lists have been given as ARR1 and ARR2 of size N and M respectively. Both the arrays/lists contain numbers from 0 to 9(i.e. single digit integer is present at every index). The idea here is to represent each array/list as an integer in itself of digits N and M.
 * 
 * You need to find the sum of both the input arrays/list treating them as two integers and put the result in another array/list i.e. output array/list will also contain only single digit at every index.
 * 
 * Output array/list(of all 0s) has been provided as a function argument. Its size will always be one more than the size of the bigger array/list. Place 0 at the 0th index if there is no carry.
 ***/

void sumOfTwoArrays(int *arr1, int n1, int *arr2, int n2, int *output)
{
    int i = n1 - 1, j = n2 - 1;
    int k = (n1 > n2) ? n1 : n2;
    
    int carry = 0, sum = 0;
    while(i >= 0 && j >= 0) {
        sum = arr1[i] + arr2[j] + carry;
        
        carry = sum / 10;
        output[k] = sum % 10;
        i--; j--; k--;
    }
    
    while(i >= 0) {
        sum = arr1[i] + carry;
        
        carry = sum / 10;
        output[k] = sum % 10;
        i--; k--;
    }
    
    while(j >= 0) {
        sum = arr2[j] + carry;
        
        carry = sum / 10;
        output[k] = sum % 10;
        j--; k--;
    }
    
    output[k] = carry;
}