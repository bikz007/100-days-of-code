/***Problem Statement**

    Given a string columnTitle that represents the column title as appears in an Excel sheet, return its corresponding column number.

    For example:

    ```
    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28
    ...
    ```

    - Examples:

        Example-1

        ```
        Input: columnTitle = "A"
        Output: 1
        ```

        Example-2:

        ```
        Input: columnTitle = "AB"
        Output: 28
        ```

        Example-3:

        ```
        Input: columnTitle = "ZY"
        Output: 701
        ```

        Example-4:

        ```
        Input: columnTitle = "FXSHRXW"
        Output: 2147483647
        ```
*/

constexpr uint8_t NUM_OF_LETTERS_IN_ENG_ALPHABET = 26;
class Solution
{
public:
    int titleToNumber(string columnTitle)
    {
        int result = 0;
        for (const char &c : columnTitle)
        {
            result = (result * NUM_OF_LETTERS_IN_ENG_ALPHABET) + (c - 'A') + 1;
        }
        return result;
    }
};