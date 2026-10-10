# Problem: https://leetcode.com/problems/minimum-sum-of-squared-difference
# TODO: This problem can be solved using heap or binary search as well. Implement those solutions as well.

"""
# Rough Work:
(n1 - n2)^2

-5 - -6 = 1
-6 - -5 = -1
-5 - 5 = -10
5 - -5 = 10

n1 - n2
+ve, if n1 > n2, n2++ (k2) or n1-- (k1)
-ve, if n2 > n1, n1++ (k1) or n2-- (k2)

k1 = 1, k2 = 1
1   4   10  12
5   8    6    9

---
-4  -4  4   3
-3  -4   3   3

k1 = 10, k2 = 5
1   4   10  12
5   8    6    9

---
-4  -4  4   3
3 3 4 3
0     0

---
2.5
5^2 + 5^2

k = 10
13 13 9 8 5 1
13 2
9 1

13 - 9 = 4
8 / 2 = 4, 0
7 / 2 = 3, 1
6 / 2 = 3, 0
5 / 2 = 2, 1
4 / 2 = 2, 0

4 4 4 3
4 3
3 1

3 / 3 = 1, 0 => 3 3 3 3
2 / 3 = 0, 2 => 4 3 3 3
1 / 3 = 0, 1 => 4 4 3 3
"""

# Intuition:
# -ve => n2 > n1 so,  n1++ (k1) or n2-- (k2)
# +ve => n1 > n2 so, n2++ (k2) or n1-- (k1)

# Time Complexity: O(n + m) where n is the length of nums1 and nums2 and m is the maximum absolute difference between nums1[i] and nums2[i]
# Space Complexity: O(m) where m is the maximum absolute difference between nums1[i] and nums2[i]
class Solution:
    def minSumSquareDiff(self, nums1: list[int], nums2: list[int], k1: int, k2: int) -> int:
        n = len(nums1)
        k = k1 + k2
        difference = [0] * (10**5 + 1)

        for i in range(n):
            difference[abs(nums1[i] - nums2[i])] += 1

        for i, _ in reversed(list(enumerate(difference))):
            freq = difference[i]
            if i == 0:
                return 0
            if freq == 0:
                continue

            if freq <= k:
                if i <= 1:
                    return 0

                difference[i - 1] += freq
                difference[i] = 0
                k -= freq
            else:
                difference[i - 1] += k
                difference[i] -= k
                break

        return sum(i * i * freq for i, freq in enumerate(difference))

        # Complicated approach trying to optimize earlier approach - Doesn't work
        # n = len(nums1)
        # k = k1 + k2
        # difference = defaultdict(int)

        # for i in range(n):
        #     difference[abs(nums1[i] - nums2[i])] += 1

        # max_abs_heap = []
        # for x in difference:
        #     heapq.heappush(max_abs_heap, (-x, difference[x]))

        # result = 0
        # while max_abs_heap:
        #     # first greatest
        #     x, freqX = heapq.heappop(max_abs_heap)
        #     x = -x

        #     print(x, freqX)

        #     if x == 0:
        #         break

        #     if k == 0:
        #         result += freqX * (x ** 2)
        #         continue

        #     # second greatest
        #     y, freqY = 0, 0
        #     if max_abs_heap:
        #         y, freqY = heapq.heappop(max_abs_heap)
        #         y = -y

        #     print(y, freqY)

        #     diff = x - y
        #     count = min(freqX * diff, k)
        #     k -= count

        #     to_decrease = count // freqX
        #     rem = count % freqX

        #     print(to_decrease, rem)

        #     newX1 = x - to_decrease
        #     newX1Count = freqX - rem

        #     newX2 = newX1 - 1
        #     newX2Count = rem

        #     if newX1 == y:
        #         newX1Count += freqY
        #         freqY = 0
        #     elif newX2 == y:
        #         newX2Count += freqY
        #         freqY = 0

        #     print(newX1, newX2, y)

        #     if freqY != 0:
        #         heapq.heappush(max_abs_heap, (-y, freqX))

        #     if newX1Count != 0:
        #         heapq.heappush(max_abs_heap, (-newX1, newX1Count))

        #     if newX2Count != 0:
        #         heapq.heappush(max_abs_heap, (-newX2, newX2Count))

        # return result

        # # Second approach - Working but TLE
        # n = len(nums1)
        # difference = [0] * n
        # k = k1 + k2

        # for i in range(n):
        #     difference[i] = abs(nums1[i] - nums2[i])

        # max_abs_heap = []
        # for x in difference:
        #     heapq.heappush(max_abs_heap, -x)

        # result = []
        # while max_abs_heap:
        #     x = -heapq.heappop(max_abs_heap)

        #     if x == 0:
        #         break

        #     if k == 0:
        #         result.append(x)
        #         result.extend(max_abs_heap)
        #         break

        #     x -= 1
        #     k -= 1

        #     heapq.heappush(max_abs_heap, -x)

        # return sum(x * x for x in result)

        # # First Approach some portion - didn't work
        # for i in range(n):
        #     if k1 == 0 and k2 == 0:
        #         break

        #     if difference[i] < 0: # -ve => n2 > n1 so,  n1++ (k1) or n2-- (k2)
        #         x = min(k1, -1 * difference[i])
        #         k1 -= x
        #         difference[i] = difference[i] + x

        #         if difference[i] != 0:

        #     elif difference[i] > 0: # +ve => n1 > n2 so, n2++ (k2) or n1-- (k1)
        #         y = min(k2, difference[i])
        #         k2 -= y
        #         difference[i] = difference[i] - y

        # return sum(x * x for x in difference)
