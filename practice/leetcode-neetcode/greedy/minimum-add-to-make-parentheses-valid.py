# Problem: https://leetcode.com/problems/minimum-add-to-make-parentheses-valid

class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        return self.minAddToMakeValidGreedy(s)
        # return self.minAddToMakeValidStack(s)

    # Time Complexity: O(n)
    # Space Complexity: O(1)
    def minAddToMakeValidGreedy(self, s: str) -> int:
        left, count = 0, 0

        for ch in s:
            if ch == '(':
                left += 1
            else:
                if left == 0:
                    count += 1
                else:
                    left -= 1
        return count + left

    # Time Complexity: O(n)
    # Space Complexity: O(n)
    def minAddToMakeValidStack(self, s: str) -> int:
        stack = list()

        count = 0
        for ch in s:
            if ch == '(':
                stack.append(ch)
            else:
                if len(stack) == 0:
                    count += 1
                else:
                    stack.pop()

        return count + len(stack)
