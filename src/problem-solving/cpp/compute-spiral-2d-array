#include <iostream>
#include <vector>

using namespace std;

enum class Direction
{
    LEFT_TO_RIGHT = 1,
    TOP_TO_BOTTOM = 2,
    RIGHT_TO_LEFT = 3,
    BOTTOM_TO_TOP = 4
};

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int left = 0, right = matrix[0].size() - 1, bottom = matrix.size() - 1, top = 0;
        Direction dir = Direction::LEFT_TO_RIGHT;
        vector<int> result;
        while (left <= right && top <= bottom)
        {
            if (dir == Direction::LEFT_TO_RIGHT)
            {
                for (int i = left; i <= right; i++)
                {
                    result.push_back(matrix[top][i]);
                }
                dir = Direction::TOP_TO_BOTTOM;
                top++;
            }

            else if (dir == Direction::TOP_TO_BOTTOM)
            {
                for (int i = top; i <= bottom; i++)
                {
                    result.push_back(matrix[i][right]);
                }
                dir = Direction::RIGHT_TO_LEFT;
                right--;
            }

            else if (dir == Direction::RIGHT_TO_LEFT)
            {
                for (int i = right; i >= left; i--)
                {
                    result.push_back(matrix[bottom][i]);
                }
                dir = Direction::BOTTOM_TO_TOP;
                bottom--;
            }

            else if (dir == Direction::BOTTOM_TO_TOP)
            {
                for (int i = bottom; i >= top; i--)
                {
                    result.push_back(matrix[i][left]);
                }
                dir = Direction::LEFT_TO_RIGHT;
                left++;
            }
        }
        return result;
    }
};