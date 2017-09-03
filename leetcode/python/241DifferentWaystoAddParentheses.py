'''
Given a string of numbers and operators, return all possible results from
computing all the different possible ways to group numbers and operators.
The valid operators are +, - and *.

Example 1
Input: "2-1-1".

((2-1)-1) = 0
(2-(1-1)) = 2
Output: [0, 2]


Example 2
Input: "2*3-4*5"

(2*(3-(4*5))) = -34
((2*3)-(4*5)) = -14
((2*(3-4))*5) = -10
(2*((3-4)*5)) = -10
(((2*3)-4)*5) = 10
Output: [-34, -14, -10, -10, 10]
'''


class Solution(object):
    def opresult(self, op, a, b):
        if op == '-':
            return a - b
        elif op == '+':
            return a + b
        else:
            return a * b

    def diffComple(self, a):
        """
        :param a: List[str]
        :return: List[int]
        """
        ans = []
        if len(a) == 1:
            ans.append(int(a[0]))
            return ans

        op = 1
        while op < len(a):
            left = a[0:op]
            right = a[op + 1:]
            for li in self.diffComple(left):
                for ri in self.diffComple(right):
                    ans.append(self.opresult(a[op], li , ri))
            op += 2
        return ans

    def diffWaysToCompute(self, input):
        """
        :type input: str
        :rtype: List[int]
        """
        a = []
        operator = ['-', '*', '+']
        s = ""
        for i in input:
            if i in operator:
                a.append(s)
                a.append(i)
                s = ""
            else:
                s = s + i
        a.append(s)
        print(a)
        return self.diffComple(a)


S = Solution()
a = "2*3-4*5"
print(S.diffWaysToCompute(a))
