"""
Given an array of unsorted numbers and a target number, find all unique quadruplets in it, whose sum is equal to the target number.
Example-1

```
Input: [4, 1, 2, -1, 1, -3], target=1
Output: [-3, -1, 1, 4], [-3, 1, 1, 2]
Explanation: Both the quadruplets add up to the target.
```

Example-2:

```
Input: [2, 0, -1, 1, -2, 2], target=2
Output: [-2, 0, 2, 2], [-1, 0, 1, 2]
Explanation: Both the quadruplets add up to the target.
```
"""


def search_quadruplets(arr, target):
    arr.sort()
    quadruplets = []
    for i in range(len(arr) - 3):
        if i > 0 and arr[i] == arr[i -
                                   1]:  # skip same element to avoid duplicate quadruplets
            continue
        for j in range(i + 1, len(arr) - 2):
            if j > i and arr[j] == arr[j - 1]:
                continue
            search_pair(arr, target, i, j, quadruplets)
    return quadruplets


def search_pair(arr, target_sum, first, second, quadruplets):
    left = second + 1
    right = len(arr) - 1
    while(left < right):
        current_sum = arr[first] + \
            arr[second] + arr[left] + arr[right]
        if current_sum == target_sum:  # found the quadruplets
            quadruplets.append(
                [arr[first], arr[second], arr[left], arr[right]])
            left += 1
            right -= 1
            while left < right and arr[left] == arr[left - 1]:
                left += 1  # skip same element to avoid duplicate quadruplets
            while left < right and arr[right] == arr[right + 1]:
                right -= 1  # skip same element to avoid duplicate quadruplets
        elif target_sum > current_sum:
            left += 1  # we need a pair with a bigger sum
        else:
            right -= 1  # we need a pair with a smaller sum
