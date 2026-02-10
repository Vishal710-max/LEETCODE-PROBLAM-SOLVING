#include <iostream>
#include <vector>
using namespace std;

/*
1382. Balance a Binary Search Tree
---------------------------------
Given the root of a Binary Search Tree (BST),
return a balanced Binary Search Tree with the same node values.

A BST is balanced if:
- The depths of the two subtrees of every node never differ by more than 1.
*/

/*
# Intuition
- An inorder traversal of a BST gives a sorted list of values.
- If we rebuild the BST from this sorted list by always choosing the middle
  element as the root, the tree will be height-balanced.
- This is similar to constructing a balanced BST from a sorted array.
*/

/*
# Approach
1. Perform an inorder traversal of the BST and store values in a vector.
2. Use divide and conquer to build a balanced BST:
   - Pick the middle element as root.
   - Recursively build left and right subtrees.
3. Return the newly built balanced BST.
*/

/*
# Complexity
- Time: O(n), where n is the number of nodes.
- Space: O(n) for storing inorder traversal.
*/

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> inorder;

    // Step 1: Inorder traversal to get sorted values
    void inorderTraversal(TreeNode* root) {
        if (!root) return;
        inorderTraversal(root->left);
        inorder.push_back(root->val);
        inorderTraversal(root->right);
    }

    // Step 2: Build balanced BST from sorted inorder array
    TreeNode* buildBalancedBST(int left, int right) {
        if (left > right) return nullptr;

        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(inorder[mid]);

        root->left = buildBalancedBST(left, mid - 1);
        root->right = buildBalancedBST(mid + 1, right);

        return root;
    }

    // Main function
    TreeNode* balanceBST(TreeNode* root) {
        inorderTraversal(root);
        return buildBalancedBST(0, inorder.size() - 1);
    }
};