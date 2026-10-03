/***
 * Given an array ‘ARR’ and an integer ‘K’, your task is to find all the count of all sub-arrays whose sum is divisible by the given integer ‘K’.
 * If there exists no subarray in the given sequence whose sum is divisible by ‘K’ then simply return ‘0’.
 * 
 * Help:
 * https://www.geeksforgeeks.org/count-sub-arrays-sum-divisible-k/
 * https://stackoverflow.com/questions/16605991/number-of-subarrays-divisible-by-k
 * https://www.youtube.com/watch?v=QM0klnvTQzk
 ***/

/*
   Approach 3:
   	Time complexity: O(N)
    Space complexity: O(K)

    Where 'N' is number elements in 'ARR' and 'K' is second given integer.
*/

int subArrayCount(vector<int> &arr, int k) {
	// HashMap to store frequency.
    unordered_map<int, int> remMap; 
    // Add base case in hashmap. 
    remMap[0] = 1;                   
    int count = 0;
    long summ = 0;
    for (int i = 0; i < arr.size(); i++) {
        summ += arr[i];

        // as the sum can be negative, taking modulo twice
        int rem = ((summ % k) + k) % k;

        // If rem already in 'remMap'.
        if (remMap.find(rem) != remMap.end()) {
            count += remMap[rem];
            remMap[rem] += 1;
        } else {
            remMap[rem] = 1;
        }
    }

    return count;
}

/*
   Approach 2:
    Time complexity: O(N + K)
    Space complexity: O(K)

    where 'N' is number elements in 'ARR' and 'K' is given second integer.
*/

int subArrayCount(vector<int> &arr, int k) {
    // To store frequency of every remainder.
    vector<int> remArr(k, 0);

    // To store prefix sum.
    long pre = 0;

    for (int i = 0; i < arr.size(); i++) {
        pre += arr[i];
        // If current remainder is 'x' then increase remainder 'x' frequency by '1'.
        remArr[((pre % k) + k) % k] = remArr[((pre % k) + k) % k] + 1;
    }

    int count = 0;  // To store count of the all subarray has sum is divisible by 'k'.

    // Iterate every occurence of remainder.
    for (int i = 0; i < k; i++) {
        if (remArr[i] > 1) {
            // Total subarray with particular remainder.
            int totalPossibleCombination = ((remArr[i] * (remArr[i] - 1)) / 2);
            count = count + totalPossibleCombination;
        }
    }

    // Add remainder '0' frequency.
    count += remArr[0];

    return count;
}

/*
// Time: O(n^2), Space: O(n)
int subArrayCount(vector<int> &arr, int k) {
    int n = arr.size();
    int *prefix = new int[n + 1];
    prefix[0] = 0;
    for(int i = 0; i < n; i++)
        prefix[i + 1] = prefix[i] + arr[i];
    
    int ctr = 0;
    for(int l = 1; l <= n; l++) {
        for(int r = l; r <= n; r++) {
            int sum = prefix[r] - prefix[l - 1];
            if(sum % k == 0)
                ctr++;
        }
    }
    return ctr;
}*/