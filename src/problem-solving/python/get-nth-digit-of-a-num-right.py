"""
Find nth digit of a number. Create a program that uses a function called digit which returns the value of the nth digit from the right of an integer argument.

- Examples:

    Example-1

    ```
    num = 9635
    n = 1
    Output: 5
    ```

    Example-2:

    ```
    num = 9635
    n = 3
    Output: 6
    ```
"""


def get_nth_digit_of_a_num_right(num, n):

    while(num > 0 and (n > 1)):
        n -= 1
        num //= 10

    if num != 0:
        return num % 10
    else:
        return 0


print(get_nth_digit_of_a_num_right(987569567, 5))
