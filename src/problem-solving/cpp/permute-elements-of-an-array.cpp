/*
Permute Elements of An Array
Link: https://www.geeksforgeeks.org/permute-the-elements-of-an-array-following-given-order/
Given an array A of n elements and a permutation P , where P[i] indicates the location where the
current A[i] goes. Apply P to A .
Example
Input: A = [a,b,c,d], P = [3,2,1,0]
Output: [d,c,b,a]
Approach: Every permutation can be represented by a collection of independent permutations, each
of which is cyclic i.e. it moves all the elements by a fixed offset wrapping around. To find and
apply the cycle that indicates entry i, just keep going forward (from i to P[i]) till we get
back at i. After completing the current cycle, find another cycle that has not yet been applied.
To check this, subtract n from P[i] after applying it. This means that if an entry in P[i] is negative,
we have performed the corresponding move.
*/

#include <iostream>
#include <vector>

void apply_permuation(std::vector<int> &A, std::vector<int> P)
{
    for (int i = 0; i < A.size(); i++)
    {
        // Check if the element at index i has not been moved by checking if P[i] is nonnegative.
        int next = i;

        while (P[next] >= 0)
        {
            std::swap(A[i], A[P[next]]);
            int temp = P[next];
            // Subtracts A.size() from an entry in A to make it negative,
            // which indicates the corresponding move has been performed.
            P[next] -= A.size();
            next = temp;
        }
    }
}

int main()
{
    std::vector<int> A{5, 6, 7, 8};
    apply_permuation(A, std::vector<int>{3, 2, 1, 0});

    for (int i = 0; i < A.size(); i++)
    {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
