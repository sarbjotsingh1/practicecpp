 //  Copyright © 2021 Kiran. All rights reserved.
 // 
 //  Problem Statement:
 //  https://www.interviewbit.com/problems/preorder-traversal/
 //
 //  Given a binary tree, return the preorder traversal of its nodes’ values. Without Recursion.
 //
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::preorderTraversal(TreeNode* A) {
    
    TreeNode* currentNode = A;
    stack<TreeNode*> s;
    vector<int> ans;
    
    while(!s.empty() || currentNode) {
        if (currentNode) {
            ans.push_back(currentNode->val);
            s.push(currentNode);
            currentNode = currentNode->left;
        } else {
            TreeNode* node = s.top();
            s.pop();
            currentNode = node->right;
        }
    }
    
    return ans;
}
