# Problem: https://leetcode.com/problems/valid-anagram

# Time Complexity: O(n + m)
# Space Complexity: O(1)
# where n is the length of s and m is the length of t
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        # freq = [0 for x in range(26)]
        # self.updateFreq(s, freq, 1)
        # self.updateFreq(t, freq, -1)
        # return all(x == 0 for x in freq)

        count = [0] * 26
        for i in range(len(s)):
            count[ord(s[i]) - ord('a')] += 1
            count[ord(t[i]) - ord('a')] -= 1

        return all(x == 0 for x in count)

    def updateFreq(self, s: str, freq: list, val: int):
        for ch in s:
            freq[ord(ch) - ord('a')] = freq[ord(ch) - ord('a')] + val
