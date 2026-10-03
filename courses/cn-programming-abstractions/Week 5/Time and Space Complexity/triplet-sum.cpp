/***
 * You have been given a random integer array/list(ARR) and a number X. Find and return the number of triplets in the array/list which sum to X.
 * Given array/list can contain duplicate elements.
 * 
 * Articles Read:
 * https://www.geeksforgeeks.org/print-all-triplets-with-given-sum/
 ***/
// Solution by TA via doubt
int tripletSum(int *arr, int n, int num)
{
	//Write your code here
    int count=0;
    sort(arr,arr+n);
    
    for(int i=0;i<n-2;i++){
        
        int l=i+1;int h=n-1;
        
        while(l<h){
            
            if(arr[i]+arr[l]+arr[h]==num){
                for(int x=h; x>l && arr[x]==arr[h];x--){
                    count++;   
                }
                l++;
            }
            else if(arr[i]+arr[l]+arr[h]<num){
                l++;
            }
            else h--;
        }
    }
    return count;
}

// Coding Ninjas Solution / Varun Sent
int pairSum(int *arr, int start, int end, int target) {


   int finalCount = 0;
	while (start < end) {
		
		if (arr[start] + arr[end] > target) {
			end--;
		}
		
		else if (arr[start] + arr[end] < target) {
			start++;
		}
			else {
			int startIndex = start;
			int endIndex = end;
		 	if (arr[start] == arr[end]) {
				int betweenIndexes = (end - start) + 1;
				finalCount += (betweenIndexes * (betweenIndexes - 1)) / 2;
				return finalCount;
			}
		
			int newStart = start + 1;
			int newEnd = end - 1;

			while (newStart <= newEnd && arr[newStart] == arr[start])
				newStart++;
			while (newStart <= newEnd && arr[newEnd] == arr[end])
				newEnd--;

			int eleFromStart = newStart - start;
			int eleFromEnd = end - newEnd;

			finalCount += (eleFromStart * eleFromEnd);

			start = newStart;
			end = newEnd;
		}
	}

	return finalCount;
}

int tripletSum(int *arr, int n, int num) {
	if (n == 0)
		return 0;

	sort(arr, arr + n);

	int finalCount = 0;

	for (int i = 0; i < n; i++) {
		int pairSumFor = num - arr[i];
		finalCount +=  pairSum(arr, i + 1, n - 1, pairSumFor);
	}

	return finalCount;
}