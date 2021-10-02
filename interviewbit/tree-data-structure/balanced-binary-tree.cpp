 //  Copyright © 2021 Kiran. All rights reserved.
 // 
 //  Problem Statement:
 //  https://www.interviewbit.com/problems/balanced-binary-tree/
 //  
 //  Given a binary tree, determine if it is height-balanced.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 

int maximum(int a, int b){
    if (a > b) return a;
    else return b;
} 
int depthOfNode(TreeNode* node) {
    if (node == NULL) {
        return 0;
    }
    
    int leftMaxDepth = depthOfNode(node->left);
    int rightMaxDepth = depthOfNode(node->right);
    
    return (maximum(leftMaxDepth, rightMaxDepth) + 1);
}

int checkNodeIsBalanced(TreeNode* node) {
    if (node == NULL) return true;
    
    int leftDepth = depthOfNode(node->left);
    int rightDepth = depthOfNode(node->right);
    
    if ((leftDepth - rightDepth) > 1 || (leftDepth - rightDepth) < -1) return false;
    else return true;
}

int checkTreeIsBalanced(TreeNode* node) {
    cout << "Checking Node: " << node->val;
    
    bool currentNodeBalanced = checkNodeIsBalanced(node);
    
    return currentNodeBalanced && checkTreeIsBalanced(node->left)
           && checkTreeIsBalanced(node->right);
}

bool balanced = true;

int checkDepthIsBalanced(TreeNode* node) {
    // cout << "Checking Node: " << node->val;
    if (node == NULL) return 0;
    
    int leftMaxHeight = checkDepthIsBalanced(node->left);
    int rightMaxHeight = checkDepthIsBalanced(node->right);
    
    if ((leftMaxHeight - rightMaxHeight) > 1 || (leftMaxHeight - rightMaxHeight) < -1) {
        balanced = false;
    }
    
    return (maximum(leftMaxHeight, rightMaxHeight) + 1);
}
 
int Solution::isBalanced(TreeNode* A) {
    //cout << "STARTING";
    
    balanced = true;

    int treeDepth = checkDepthIsBalanced(A);
    
    return balanced;
    
}
