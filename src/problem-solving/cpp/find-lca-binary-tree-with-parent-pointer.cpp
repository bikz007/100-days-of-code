TreeNode/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode *parent;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL), parent(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        auto iter0 = p, iter1 = q;
        auto depth0 = GetDepth(p), depth1 = GetDepth(q);

        if(depth1> depth0)
        {
            std::swap(iter0,iter1);
        }

        int depth_diff = std::abs(depth0- depth1);
        while(depth_diff--)
        {
            iter0 = iter0->parent;
        }

        while(iter0 != iter1)
        {
            iter0 = iter0->parent;
            iter1 = iter1->parent;
        }
        return iter0;
     }

    int GetDepth(TreeNode* node)
    {
        int result = 0;
        while(node->parent)
        {
            ++result;
            node = node->parent;
        }

        return result;
    }

};