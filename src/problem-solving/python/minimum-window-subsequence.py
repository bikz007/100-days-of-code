"""
Given strings str1 and str2, find the minimum (contiguous) substring sub_str of str1, such that every character of str2 appears in sub_str in the same order as it is present in str2.

If there is no window in str1 that covers all characters in str2, return an empty string.
If there are multiple minimum-length windows, return the one with the leftmost starting index.

**Constraints:**

- 11 ≤ `str1.length` ≤ 2×10^3
- 11 ≤ `str2.length` ≤ 100
- `str1` and `str2` consist of uppercase and lowercase English letters.
- Examples:

    Example-1

    ```
    Input:
    str1: geeksforgeeks
    str2: eksrg
    Output:
    eksforg
    Explanation:
    Eksforg satisfies all required conditions. str2 is its subsequence and it is longest and leftmost among all possible valid substrings of str1.
    ```

    Example-2:

    ```
    Input:
    str1: abcdebdde
    str2: bde
    Output:
    bcde
    Explanation:
    "bcde" is the answer and "deb" is not a smaller window because the elements of T in the window must occur in order.
    ```
"""


def min_window(str1, str2):
    # Save the size of str1 and str2
    size_str1, size_str2 = len(str1), len(str2)
    # Initialize length to a very large number (infinity)
    length = float('inf')
    # Initialize pointers to zero and the min_subsequence to an empty
    # string
    index_s1, index_s2 = 0, 0
    min_subsequence = ""

    # Process every character of str1
    while index_s1 < size_str1:
        # Check if the character pointed by index_s1 in str1
        # is the same as the character pointed by index_s2 in str2
        if str1[index_s1] == str2[index_s2]:
            # If the pointed character is the same
            # in both strings increment index_s2
            index_s2 += 1
            # Check if index_s2 has reached the end of str2
            if index_s2 == size_str2:
                # At this point the str1 contains all characters of
                # str2
                start, end = index_s1, index_s1 + 1
                # Initialize start to the index where all characters of
                # str2 were present in str1
                index_s2 -= 1
                # Decrement pointer index_s2 and start a reverse loop
                while index_s2 >= 0:
                    # Decrement pointer index_s2 until all characters of
                    #  str2 are found in str1
                    if str1[start] == str2[index_s2]:
                        index_s2 -= 1
                    # Decrement start pointer everytime to find the
                    # starting point of the required subsequence
                    start -= 1
                start += 1
                # Check if length of sub sequence pointed
                # by start and end pointers is less than current min
                # length
                if end - start < length:
                    # Update length if current sub sequence is shorter
                    length = end - start
                    # Update minimum subsequence string
                    # to this new shorter string
                    min_subsequence = str1[start:end]

                # Set index_s1 to start to continue checking in str1
                # after this discovered subsequence
                index_s1 = start
                index_s2 = 0

        # Increment pointer index_s1 to check next character in str1
        index_s1 += 1

    return min_subsequence
