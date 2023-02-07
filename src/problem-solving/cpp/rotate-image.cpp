#include <iostream>
#include <vector>

class Solution
{
public:
    void rotate(std::vector<std::vector<int>> &matrix)
    {
        int left = 0;
        int right = matrix.size() - 1;

        while (left < right)
        {
            int top = left, bottom = right;
            for (int i = 0; i < (right - left); i++)
            {
                int temp_top_left = matrix[top][left + i];

                // top-left = bottom-left
                matrix[top][left + i] = matrix[bottom - i][left];
                // bottom-left = bottom-right
                matrix[bottom - i][left] = matrix[bottom][right - i];
                // bottom-right = top-right
                matrix[bottom][right - i] = matrix[top + i][right];
                // top-right = top-left
                matrix[top + i][right] = temp_top_left;
            }
            ++left;
            --right;
        }
    }
};