# Problem: https://leetcode.com/problems/top-k-frequent-elements
# TODO: This problem can be solved using heap or bucket sort. Implement those solutions as well.

from collections import defaultdict

class Solution:
    def topKFrequent(self, nums: list[int], k: int) -> list[int]:
        return self.topKFrequentHashMapSorting(nums, k)
        # return self.topKFrequentHashMap(nums, k)

    # Time Complexity: O(n log n)
    # Space Complexity: O(n)
    # where n is the length of nums
    def topKFrequentHashMapSorting(self, nums: list[int], k: int) -> list[int]:
        myDict = defaultdict(int)
        for n in nums:
            myDict[n] += 1

        # create the freq list [frequency, number]
        freqList = []
        for x, y in myDict.items():
            freqList.append([y, x])

        # sort the freq list
        freqList.sort()

        # iterate and get the result from last
        result = []
        while k > 0:
            removed = freqList.pop()
            result.append(removed[1])
            k -= 1
        return result

    # Time Complexity: O(n * k)
    # Space Complexity: O(n)
    # where n is the length of nums and k is the number of most frequent elements to return
    def topKFrequentHashMap(self, nums: list[int], k: int) -> list[int]:
        myDict = defaultdict(int)
        for n in nums:
            myDict[n] += 1

        result = []
        while k > 0:
            maxFreq = 0
            num = 0

            for x in myDict.keys():
                currFreq = myDict[x]
                if currFreq >= maxFreq:
                    maxFreq = currFreq
                    num = x

            result.append(num)
            myDict.pop(num)
            k -= 1

        return result
