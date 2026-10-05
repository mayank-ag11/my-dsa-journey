# Problem: https://leetcode.com/problems/score-of-parentheses

# Time Complexity: O(n)
# Space Complexity: O(n)
# where n is the length of s
class Solution:
    def scoreOfParentheses(self, s: str) -> int:
        stack = list()

        totalScore = 0

        for ch in s:
            if ch == '(':
                stack.append((ch, 0))
            else:
                curr = stack.pop()
                score = 1 if curr[1] == 0 else curr[1] * 2

                if len(stack) == 0:
                    totalScore += score
                else:
                    top = stack[-1]
                    stack[-1] = (top[0], score + top[1])
        return int(totalScore)
