"""
Given a number N. The task is to find the largest and the smallest digit of the number.

- Examples:

    Example-1

    ```
    Input : N = 2346
    Output : 6 2
    6 is the largest digit and 2 is smallest
    Input : N = 5
    Output : 5 5
    ```
"""


def largest_smallest_digits(n):
    largest = 0
    smallest = 9
    while n:
        r = n % 10
        largest = max(largest, r)
        smallest = min(smallest, r)
        n //= 10

    return (largest, smallest)
