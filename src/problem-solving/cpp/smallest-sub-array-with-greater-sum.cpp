/*
Given an array of positive integers and a number ‘S,’ find the length of the smallest contiguous subarray whose sum is greater than or equal to ‘S’. Return 0 if no such subarray exists.

- Examples:

    Example-1

    ```
    Input: [2, 1, 5, 2, 3, 2], S=7
    Output: 2
    Explanation: The smallest subarray with a sum greater than or equal to ‘7’ is [5, 2].
    ```

    Example-2:

    ```
    Input: [2, 1, 5, 2, 8], S=7
    Output: 1
    Explanation: The smallest subarray with a sum greater than or equal to ‘7’ is [8].
    ```

    Example-3:

    ```
    Input: [3, 4, 1, 1, 6], S=8
    Output: 3
    Explanation: Smallest subarrays with a sum greater than or equal to ‘8’ are [3, 4, 1] or [1, 1, 6].
    ```

    Example-4:

    ```
    Input: target = 4, nums = [1,4,4]
    Output: 1
    ```

    Example-5:

    ```
    Input: target = 11, nums = [1,1,1,1,1,1,1,1]
    Output: 0
    ```
*/

using namespace std;

#include <iostream>
#include <limits>
#include <vector>

class MinSizeSubArraySum
{
public:
    static int findMinSubArray(int S, const vector<int> &arr)
    {
        int small_sub_arr_len = std::numeric_limits<int>::max();
        int win_start = 0;
        int win_sum = 0;
        for (int win_end = 0; win_end < arr.size(); win_end++)
        {
            win_sum += arr[win_end];
            while (win_sum >= S)
            {
                small_sub_arr_len = min(small_sub_arr_len, win_end - win_start + 1);
                win_sum -= arr[win_start++];
            }
        }
        return small_sub_arr_len == std::numeric_limits<int>::max() ? 0 : small_sub_arr_len;
    }
};