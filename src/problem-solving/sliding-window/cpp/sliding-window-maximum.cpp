/*
- **Problem Statement**

    Given an integer array nums and a window of size w, find the current maximum value in the window as it slides through the entire array.

    Note: If the window size is greater than the array size, we consider the entire array as a single window.

    - Examples:

        Example-1

        ```
        Input: nums = [1,3,-1,-3,5,3,6,7], w = 3
        Output: [3,3,5,5,6,7]
        Explanation:
        Window position                Max
        ---------------               -----
        [1  3  -1] -3  5  3  6  7       3
         1 [3  -1  -3] 5  3  6  7       3
         1  3 [-1  -3  5] 3  6  7       5
         1  3  -1 [-3  5  3] 6  7       5
         1  3  -1  -3 [5  3  6] 7       6
         1  3  -1  -3  5 [3  6  7]      7
        ```

        Example-2:

        ```
        Input: nums = [1], w = 1
        Output: [1]
        ```

        Example-3:

        ```
        w = 2

        nums = [-4, 5, 4, -4, 4, 6, 7]

        Output: [5, 5, 4, 4, 6, 7]
        ```

        Example-4:

        ```
        w = 10

        nums = [-4, 5, 4, -4, 4 , 6, 7]

        Output: [7]
        ```
*/
#include <iostream>
#include <deque>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int window_size)
    {
        vector<int> result;
        // Let’s now return an empty list if nums is empty
        if (nums.size() == 0)
        {
            return result;
        }
        // If windowSize is greater than the array size,
        // set the windowSize to nums.size()
        if (window_size > nums.size())
        {
            window_size = nums.size();
        }
        // Initializing doubly ended queue for storing indices
        deque<int> window;
        // Find out first maximum in the first window
        for (int i = 0; i < window_size; i++)
        {
            // Find out first maximum in the first window
            while ((!window.empty()) && (nums[i] >= nums[window.back()]))
            {
                window.pop_back();
            }
            // Add current element at the back of the queue
            window.push_back(i);
        }
        // Appending the largest element in the window to the result
        result.push_back(nums[window.front()]);

        for (int i = window_size; i < nums.size(); i++)
        {
            // remove all numbers that are smaller than current number
            // from the tail of list
            while ((!window.empty()) && (nums[i] >= nums[window.back()]))
            {
                window.pop_back();
            }
            // Remove first index from the window deque if
            // it doesn't fall in the current window anymore
            if ((!window.empty()) && (window.front() <= (i - window_size)))
            {
                window.pop_front();
            }
            // Add current element at the back of the queue
            window.push_back(i);
            result.push_back(nums[window.front()]);
        }

        return result;
    }
};