/*
Sara is solving a math problem in which she has given an integer N and her task is to find the number of operations required to convert N into 1. Where in one operation you replace the number with its second-highest divisor.

- Examples:

    Example-1

    ```
    Sample Input:-
    100
    Sample Output:-
    4
    Explanation:-
    100 - > 50
    50 - > 25
    25 - > 5
    5 - > 1
    ```

    Example-2:

    ```
    Sample Input:-
    10
    Sample Output:-
    2
    ```

    Example-3:

    ```

    ```

    Example-4:

    ```

    ```
*/

int divisor_problem(int num)
{
    int result = 0;

    while (num > 1)
    {
        int count = 2;

        while (num % count != 0)
        {
            count++;
        }

        num /= count;
        result++;
    }

    return result;
}