class Solution:
    def generate(self, numRows):
        result = [[1]]
        for i in range(1, numRows):
            result.append(self.calcNxtRow(i, result[-1]))
        return result

    def calcNxtRow(self, lenOfRow, row):
        headPtr = -1
        tailPtr = 0
        result = []
        while(headPtr < lenOfRow):
            num1 = 0 if headPtr == -1 else row[headPtr]
            num2 = 0 if tailPtr == lenOfRow else row[tailPtr]
            result.append(num1 + num2)
            headPtr += 1
            tailPtr += 1
        return result
