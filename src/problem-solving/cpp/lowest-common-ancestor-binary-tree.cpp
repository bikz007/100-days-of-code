#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// Node class
class Node
{
public:
    int val;
    Node *left, *right;

    Node(int Val)
    {
        val = Val;
        left = nullptr;
        right = nullptr;
    }
};
// Lists to store the path
vector<int> path1;
vector<int> path2;

// Function to find the path from the root node
// to the target node.
bool findPath(Node *root, int val,
              vector<int> &path)
{
    // Returnig false if we encounter a nullptr node.
    if (root == nullptr)
        return false;

    path.push_back(root->val);

    // Returning true, if we encounter the
    // target node.
    if (root->val == val)
    {
        return true;
    }

    // Returning true if we find the
    // target node in any of the subtree.
    if (findPath(root->left, val, path) || findPath(root->right, val, path))
    {
        return true;
    }

    // Backtrack by removing the last element
    // of the path list.
    path.pop_back();

    // Returning false if nothing worked out.
    return false;
}

// Helper function to find the LCA
int findLCA(Node *root, int n1, int n2)
{
    // Using a function to find the path from
    // root to n1 or n2.
    if (!findPath(root, n1, path1) || !findPath(root, n2, path2))
    {
        cout << "Please enter valid input" << endl;
        return -1;
    }

    int ind;
    // Now iterate over the path list found.
    for (ind = 0; ind < path1.size() && ind < path2.size(); ind++)
    {
        // If there is a mismatch break the loop.
        if (path1[ind] != path2[ind])
            break;
    }

    // Return the node encountered just before
    // the mismatch.
    return path1[ind - 1];
}

// Function to find the LCA
static int LCA(Node *root, int n1, int n2)
{
    path1.clear();
    path2.clear();

    return findLCA(root, n1, n2);
}

int main()
{
    // Making the following tree
    //          1
    //         / \
    // 	      /   \
    // 	     2     3
    // 	    / \     \
    //     /   \     \
    //    4     5     6
    //     \         / \
    //      \       /   \
    //       7     8     9

    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->left->right = new Node(7);
    root->left->right = new Node(5);
    root->right = new Node(3);
    root->right->right = new Node(6);
    root->right->right->left = new Node(8);
    root->right->right->right = new Node(9);

    cout << "LCA of 4 and 5 is " << LCA(root, 4, 5) << endl;
    cout << "LCA of 7 and 4 is " << LCA(root, 7, 4) << endl;
    cout << "LCA of 5 and 8 is " << LCA(root, 5, 8) << endl;
    // Passing the wrong input
    cout << "LCA of 5 and 10 is " << LCA(root, 5, 10) << endl;
}