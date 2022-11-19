"""
Write an algorithm to determine if a number `n` is happy.

A **happy number** is a number defined by the following process:

- Starting with any positive integer, replace the number by the sum of the squares of its digits.
- Repeat the process until the number equals 1 (where it will stay), or it **loops endlessly in a cycle** which does not include 1.
- Those numbers for which this process **ends in 1** are happy.

Return `true` *if* `n` *is a happy number, and* `false` *if not*.
Example-1

```
Input: n = 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
```

Example-2:

```
Input: n = 2
Output: false
```

Example-3:

```
Input: 23
Output: true (23 is a happy number)
Explanations: Here are the steps to find out that 23 is a happy number.
2^2 + 3^2 = 4 + 9 = 13
1^2 + 3^2 = 1 + 9 = 10
1^2 + 0^2 = 1 + 0 = 1
```

Example-4:
```
Input: 12
Output: false (12 is not a happy number)
```
"""


def find_happy_number(num):
    slow, fast = num, num

    while True:
        slow = find_squared_sum(slow)
        fast = find_squared_sum(find_squared_sum(fast))

        if slow == fast:
            break

    return slow == 1


def find_squared_sum(num):
    result = 0

    while num:
        digit = num % 10

        result += digit * digit

        num //= 10

    return result


def main():
    print(find_happy_number(23))
    print(find_happy_number(12))


main()
