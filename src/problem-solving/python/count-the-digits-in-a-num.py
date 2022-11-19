"""
Given a number N, the task is to return the count of digits in this number.

- Examples:

    Example-1

    ```
    Input: 1567
    Output: 4
    ```

    Example-2:

    ```
    Input: 15785645353546
    Output: 15
    ```

    Example-3:

    ```
    Input: 35
    Output: 2
    ```

    Example-4:

    ```
    Input: 0
    Output: 1
    ```
"""


def countDigit(n):
    if n // 10 == 0:
        return 1
    return 1 + countDigit(n // 10)
