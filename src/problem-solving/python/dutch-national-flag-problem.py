"""
Given an array containing 0s, 1s and 2s, sort the array in-place. You should treat numbers of the array as objects, hence, we can’t count 0s, 1s, and 2s to recreate the array.
The flag of the Netherlands consists of three colors: red, white and blue; and since our input array also consists of three different numbers that is why it is called Dutch National Flag problem.
Examples:
    Example-1
        Input: [1, 0, 2, 1, 0]
        Output: [0, 0, 1, 1, 2]
    Example-2:
        Input: [2, 2, 0, 1, 2, 0]
        Output: [0, 0, 1, 2, 2, 2,]
"""


class Solution:
    def sort012(self, arr, n):
        lo = 0
        hi = n - 1
        mid = 0
        while mid <= hi:
            if arr[mid] == 0:
                arr[lo], arr[mid] = arr[mid], arr[lo]
                lo = lo + 1
                mid = mid + 1
            elif arr[mid] == 1:
                mid = mid + 1
            else:
                arr[mid], arr[hi] = arr[hi], arr[mid]
                hi = hi - 1
