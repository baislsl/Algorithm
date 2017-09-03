'''
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
For example,

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.

Given target = 20, return false.


'''


class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        m = len(matrix)
        if m == 0:
            return False
        n = len(matrix[0])
        if n == 0:
            return False
        left = top = 0
        right = n - 1
        bottom = m - 1
        # print(left, right, top, bottom)
        while left < right or top < bottom:
            if left > right or top > bottom:
                return False
            if matrix[top][right] > target:
                right = right - 1
                continue
            if matrix[bottom][left] < target:
                left = left + 1
                continue
            if matrix[top][right] < target:
                top = top + 1
                continue
            if matrix[bottom][left] > target:
                bottom = bottom - 1
                continue
            break
        if matrix[bottom][left] == target:
            return True
        else:
            return False


a = [[1, 4, 7, 11, 15], [2, 5, 8, 12, 19], [3, 6, 9, 16, 22], [10, 13, 14, 17, 24], [18, 21, 23, 26, 30]]
b = [[0, -1, 0, 0]]
s = Solution()
print(s.searchMatrix([[1], [1]], 2))
