/***
 * You are given an array of unique integers that contain numbers in random order. You have to find the longest possible sequence of consecutive numbers using the numbers from given array.
 * You need to return the output array which contains starting and ending element. If the length of the longest possible sequence is one, then the output array must contain only single element.
 * Note:
    1. Best solution takes O(n) time.
    2. If two sequences are of equal length, then return the sequence starting with the number whose occurrence is earlier in the array.
 * Testcase: Input => n = 7, arr = [3 7 2 1 9 8 41]
             Output => 7 9
 ***/
#include <unordered_map>

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {
    unordered_map<int, int> map;
    
    for(int i = 0; i < n; i++)
        map[arr[i]] = i;
    
    int s, e, si, ctr, maxi = 0;
    for(int i = 0; i < n; i++) {
        if(map.count(arr[i]) > 0) {
            ctr = 1;
            int x = arr[i];
            while(map.count(x - 1) > 0) {
                ctr++;
                x--;
            }
            int y = arr[i];
            while(map.count(y + 1) > 0) {
                ctr++;
                y++;
            }
            
            if(ctr > maxi or (ctr == maxi and map[x] < si)) {
                s = x;
                si = map[x];
                e = y;
                maxi = ctr;
            }
            
            for(int j = x; j <= y; j++)
               map.erase(j);
        }
    }
    vector<int> v;
    if(maxi == 1)
        v.push_back(s);
    
    else {
        v.push_back(s);
        v.push_back(e);
    }
    return v;
}

// Coding Ninjas Solution
/*
Time complexity: O(N)
Space complexity: O(N)
where N is the length of the input array
*/
#include <unordered_map>
vector < int > longestConsecutiveIncreasingSequence(int * arr, int n) {
    unordered_map < int, bool > visitedElements;
    unordered_map < int, int > elementToIndexMapping;
    for (int i = 0; i < n; i++) {
        elementToIndexMapping[arr[i]] = i;
        if (visitedElements.count(arr[i]) == 0) {
            visitedElements[arr[i]] = true;
        }
    }
    vector < int > longestSequence;
    int globalMaxSequenceLength = 1;
    int globalMinStartIndex = 0;
    for (int i = 0; i < n; i++) {
        int num = arr[i];
        int currentMinStartIndex = i;
        int count = 0;
        int tempNum = num;
        // Forward
        while (visitedElements.count(tempNum) == 1 &&
            visitedElements[tempNum] == true) {
            visitedElements[tempNum] = false;
            count++;
            tempNum++;
        }
        // Backward
        tempNum = num - 1;
        while (visitedElements.count(tempNum) == 1 &&
            visitedElements[tempNum] == true) {
            visitedElements[tempNum] = false;
            count++;
            currentMinStartIndex = elementToIndexMapping[tempNum];
            tempNum--;
        }
        if (count > globalMaxSequenceLength) {
            globalMaxSequenceLength = count;
            globalMinStartIndex = currentMinStartIndex;
        } else if (count == globalMaxSequenceLength) {
            if (currentMinStartIndex < globalMinStartIndex) {
                globalMinStartIndex = currentMinStartIndex;
            }
        }
    }
    int globalStartNum = arr[globalMinStartIndex];
    longestSequence.push_back(globalStartNum);
    if (globalMaxSequenceLength > 1) {
        longestSequence.push_back(globalStartNum + globalMaxSequenceLength - 1);
    }
    return longestSequence;

}