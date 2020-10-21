// 938. Range Sum of BST
// Easy

// Given the root node of a binary search tree, return the sum of values of all nodes with value between L and R (inclusive).

// The binary search tree is guaranteed to have unique values.

 

// Example 1:

// Input: root = [10,5,15,3,7,null,18], L = 7, R = 15
// Output: 32

// Example 2:

// Input: root = [10,5,15,3,7,13,18,1,null,6], L = 6, R = 10
// Output: 23

 

// Note:

//     The number of nodes in the tree is at most 10000.
//     The final answer is guaranteed to be less than 2^31.




/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
//    int seed-preorder(TreeNode* node, int L, int R){
//        int sum = 0;
//        return sum;
//    }
    void preorder(TreeNode* node, int& sum, int L, int R){
        //Root-->Left-->Right 
        if (node->val >= L && node->val <= R)
        {
            sum += node->val;
        }
        if (node->left != NULL)
        {
            preorder(node->left, sum, L, R);   
        }
        if (node->right != NULL)        
        {
            preorder(node->right, sum, L, R);
        }
    }
    int rangeSumBST(TreeNode* root, int L, int R) {
        int sum = 0;
        preorder(root, sum, L, R);
        return sum;
    }
};