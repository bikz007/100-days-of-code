#include <iostream>

class Solution
{
public:
    int replace_and_remove(int size_of_s, char s[])
    {
        int write_idx = 0, a_count = 0;
        // Forward pass remove 'b's and count 'a's
        for (int i = 0; i < size_of_s; i++)
        {
            if (s[i] != 'b')
            {
                s[write_idx++] = s[i];
            }
            if (s[i] == 'a')
            {
                ++a_count;
            }
        }

        int curr_idx = write_idx - 1;
        write_idx = write_idx + a_count - 1;
        int final_size = write_idx + 1;
        // backward pass replace 'a' with 'dd'
        while (curr_idx >= 0)
        {
            if (s[curr_idx] == 'a')
            {
                s[write_idx--] = 'd';
                s[write_idx--] = 'd';
            }
            else
            {
                s[write_idx--] = s[curr_idx];
            }

            --curr_idx;
        }

        return final_size;
    }
};

int main()
{
    Solution s{};
    char str[5]= {'a','b','a','c'};
    auto final_size = s.replace_and_remove(4,str);

    for (int i = 0; i < 5; i++)
    {
        std::cout << str[i] << "\n";
    }
    
    return 0;
}