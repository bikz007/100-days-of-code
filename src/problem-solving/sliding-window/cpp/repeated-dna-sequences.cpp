/*
Given a string s that represents a DNA sequence, and a number k, return all the contiguous sequences (substrings) of length k that occur more than once in the string. The order of the returned subsequences does not matter. If no repeated subsequence is found, the function should return an empty set.

The DNA sequence is composed of a series of nucleotides abbreviated as

A, C, G, T. For example, ACGAATTCCG is a DNA sequence. When studying DNA, it is useful to identify repeated sequences in it.

**Constraints:**

- 11 ≤ `s.length` ≤ 10^4
- `s[i]` is either *A*, *C*, *G*, or *T*.
- Examples:

    Example-1

    ```
    s = “AGCTGAAAGCTTAGCTG”

    k = 5

    output: [AGCTG]
    ```

    Example-2:

    ```
    s = “AGAGCTCCAGAGCTTG”

    k = 6

    output: [AGAGCT]
    ```

    Example-3:

    ```
    s = “ATATATATATATATAT”

    k = 6

    output: [ATATAT, TATATA]
    ```
*/

std::set<std::string> FindRepeatedSequences(std::string s, int k)
{
    int windowSize = k;
    if (s.size() <= windowSize)
    {
        return {};
    }
    // parameters of rolling hash
    int base = 4;                                  // 'a', the hash parameter
    int hiPlaceValue = std::pow(base, windowSize); // a^k, the highest place value
    // mapping of a character into an integer
    std::map<char, int> mapping;
    mapping['A'] = 1;
    mapping['C'] = 2;
    mapping['G'] = 3;
    mapping['T'] = 4;
    std::vector<int> numbers{};
    for (int i = 0; i < s.size(); i++)
    {
        numbers.push_back(mapping[s[i]]);
    }
    int hashing = 0;
    std::set<int> substringHashes{};
    std::set<std::string> output{};
    // iterate over all window-sized substrings
    for (int start = 0; start < (s.size() - windowSize + 1); start++)
    {
        // hash function of current subsequence
        if (start != 0)
        {
            hashing = hashing *base
                hashing -= numbers[start - 1] *hiPlaceValue
                    hashing += numbers[start + windowSize - 1];
        }
        else
        {
            for (int end = 0; end < windowSize; end++)
            {
                hashing = hashing * base + numbers[end];
            }
        }
        // subsequence and output sets
        if (substringHashes.find(hashing) != substringHashes.end())
        {
            output.insert(s.substr(start, windowSize));
        }
        substringHashes.insert(hashing);
    }
    return output;
}
// Driver code
int main()
{
    std::vector<std::string> inputsString = {
        "ACGT", "AGACCTAGAC", "AAAAACCCCCAAAAACCCCCC",
        "GGGGGGGGGGGGGGGGGGGGGGGGG", "TTTTTCCCCCCCTTTTTTCCCCCCCTTTTTTT",
        "TTTTTGGGTTTTCCA", "", "AAAAAACCCCCCCAAAAAAAACCCCCCCTG", "ATATATATATATATAT"};
    std::vector<int> inputsK = {3, 3, 8, 12, 10, 14, 10, 10, 6};

    for (int i = 0; i < inputsK.size(); i++)
    {
        std::cout << i + 1 << ".\tInput Sequence: '" << inputsString[i] << "'\n";
        std::cout << "\tk: " << inputsK[i] << "\n";
        std::cout << "\tRepeated Subsequence: "
                  << Print(FindRepeatedSequences(inputsString[i], inputsK[i])) << "\n";
        std::cout << std::string(100, '-') << "\n";
    }
}