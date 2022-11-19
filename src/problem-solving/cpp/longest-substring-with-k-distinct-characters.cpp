/*
Given a string, find the length of the longest substring in it with no more than K distinct characters.

- Examples:

    Example-1

    ```
    Input: String="araaci", K=1
    Output: 2
    Explanation: The longest substring with no more than '1' distinct characters is "aa".
    ```

    Example-2:

    ```
    Input: String="araaci", K=2
    Output: 4
    Explanation: The longest substring with no more than '2' distinct characters is "araa".
    ```

    Example-3:

    ```
    Input: String="cbbebi", K=3
    Output: 5
    Explanation: The longest substrings with no more than '3' distinct characters are "cbbeb" & "bbebi".
    ```

    Example-4:

    ```
    Input: String="cbbebi", K=10
    Output: 6
    Explanation: The longest substring with no more than '10' distinct characters is "cbbebi".
    ```
*/

using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>

class LongestSubstringKDistinct
{
public:
    static int findLength(const string &str, int k)
    {
        int maxLength = 0;
        std::unordered_map<char, int> char_table;
        int l = 0;
        for (int r = 0; r < str.length(); r++)
        {
            char_table[str[r]]++;
            while (char_table.size() > k)
            {
                char_table[str[l]]--;
                if (char_table[str[l]] == 0)
                {
                    char_table.erase(str[l]);
                }
                ++l;
            }
            maxLength = std::max(maxLength, r - l + 1);
        }
        return maxLength;
    }
};