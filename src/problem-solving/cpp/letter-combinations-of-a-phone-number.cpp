#include <array>
constexpr int NUM_OF_DIGITS = 10;

const array<string, NUM_OF_DIGITS> digit_map = {{"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}};

class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.size() == 0)
        {
            return vector<string>({});
        }
        string partial_mnemonic(digits.size(), 0);
        vector<string> mnemonics;
        letterCombinationsHelper(digits, 0, &partial_mnemonic, &mnemonics);
        return mnemonics;
    }

    void letterCombinationsHelper(const string &digits, int digitIdx, string *partial_mnemonic, vector<string> *mnemonics)
    {
        if (digitIdx == digits.size())
        {
            mnemonics->push_back((*partial_mnemonic));
        }
        else
        {
            for (const char c : digit_map[digits[digitIdx] - '0'])
            {
                (*partial_mnemonic)[digitIdx] = c;
                letterCombinationsHelper(digits, digitIdx + 1, partial_mnemonic, mnemonics);
            }
        }
    }
};