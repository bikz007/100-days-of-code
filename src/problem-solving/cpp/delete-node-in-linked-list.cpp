/**
 * @brief There is a singly-linked list `head` and we want to delete a node `node` in it.

You are given the node to be deleted `node`. You will **not be given access** to the first node of `head`. All the values of the linked list are **unique.**

- Examples:

    Example-1

    ```
    Input: head = [4,5,1,9], node = 5
    Output: [4,1,9]
    Explanation: You are given the second node with value 5, the linked list should become 4 -> 1 -> 9 after calling your function.
    ```

    Example-2:

    ```
    Input: head = [4,5,1,9], node = 1
    Output: [4,5,9]
    Explanation: You are given the third node with value 1, the linked list should become 4 -> 5 -> 9 after calling your function.
    ```
 *
 */
// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        if (!node)
        {
            return;
        }

        if (node->next)
        {
            auto next_node_data = node->next->val;
            auto next_node = node->next;
            auto next_to_next_node = node->next->next;
            node->val = next_node_data;
            node->next = next_to_next_node;
            delete next_node;
        }
        else // if last node
        {
            delete node;
        }
    }
};