/***
 * Given an integer array A of size n. Find and print all the leaders present in the input array. An array element A[i] is called Leader, if all the elements following it (i.e. present at its right) are less than or equal to A[i].
 * Print all the leader elements separated by space and in the same order they are present in the input array.
 ***/
bool isLeader(int *arr, int n) {
    int x = arr[0];
    for(int i=1; i<n; i++)
        if(arr[i] > x)
            return false;
    return true;
}

void Leaders(int* arr,int len)
{
	for(int i=0; i<len; i++) {
        if(isLeader(&arr[i], len-i))
            cout << arr[i] << ' ';
    }
}

// Coding Ninjas Solution
// Time Complexity of this code is O(n)
void Leaders(int* arr,int len){
    int j=0;
    int *save = new int[len];
    int largest=INT_MIN; //largest contains the maximum value of leading array.
    for(int i=len-1;i>=0;i--) {
        // if element at current index is greater than largest then put it in array and make it largest;
        if(arr[i]>=largest) {
            save[j]=arr[i];
            j++;
            largest=arr[i];
        }
    }
    // Print the array in reverse order...
    for(int i=j-1;i>=0;i--) {
        cout<<save[i] << " ";
    }
}