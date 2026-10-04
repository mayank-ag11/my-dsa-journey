# Problem: https://leetcode.com/problems/valid-sudoku

from collections import defaultdict
import math

# Rough Work:
# 9 * 9

# 0 1 2
# 3 4 5
# 6 7 8

# 00 01 02   03 04 05   06 07 08
# 10 11 12   13 14 15   16 17 18
# 20 21 22   23 24 25   26 27 28

# 30 31 32   33 34 35   36 37 38
# ...
# 60 61 62   63 64 65   66 67 68

class Solution:
    def isValidSudoku(self, board: list[list[str]]) -> bool:
        return self.isValidSudokuUsingHashSet(board)
        # return self.isValidSudokuUsingFreqTable(board)

    # Time Complexity: O(n^2)
    # Space Complexity: O(n^2)
    # where n is the length of board
    def isValidSudokuUsingHashSet(self, board: list[list[str]]) -> bool:
        cols = defaultdict(set)
        rows = defaultdict(set)
        squares = defaultdict(set)

        for r in range(9):
            for c in range(9):
                if board[r][c] == ".":
                    continue
                if ( board[r][c] in rows[r]
                    or board[r][c] in cols[c]
                    or board[r][c] in squares[(r // 3, c // 3)]):
                    return False

                cols[c].add(board[r][c])
                rows[r].add(board[r][c])
                squares[(r // 3, c // 3)].add(board[r][c])

        return True

    # Time Complexity: O(n^2)
    # Space Complexity: O(n^2)
    # where n is the length of board
    def isValidSudokuUsingFreqTable(self, board: list[list[str]]) -> bool:
        rowFreq = [[0 for x in range(9)] for x in range(9)]
        colFreq = [[0 for x in range(9)] for x in range(9)]
        boxFreq = [[0 for x in range(9)] for x in range(9)]

        boxIndex = 0
        for i in range(len(board)):
            boxRowIndex = math.floor(i/3) * 3

            for j in range(len(board[i])):
                if(board[i][j] == "."):
                    continue

                boxColIndex = math.floor(j/3)
                boxIndex = boxRowIndex + boxColIndex

                currNum = int(board[i][j]) - 1

                boxFreq[boxIndex][currNum] += 1
                rowFreq[i][currNum] += 1
                colFreq[j][currNum] += 1

        # Check if any cell in rowFreq, colFreq, or boxFreq is greater than 1
        if (any(val > 1 for row in rowFreq for val in row) or
            any(val > 1 for col in colFreq for val in col) or
            any(val > 1 for box in boxFreq for val in box)):
            return False

        return True
