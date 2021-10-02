 //  Copyright © 2021 Kiran. All rights reserved.
 // 
 //  Problem Statement:
 //  https://www.interviewbit.com/problems/postorder-traversal/
 //  
 //  Given a binary tree, return the Postorder traversal of its nodes values.
 //
 //  NOTE: Using recursion is not allowed.
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
vector<int> Solution::postorderTraversal(TreeNode* A) {
    
    TreeNode* currentNode = A;
    stack<TreeNode*> leftStack;
    stack<TreeNode*> rightStack;
    vector<int> ans;
    unordered_map<TreeNode*, bool> visited;
    TreeNode* prev;
    
    while(!leftStack.empty() || currentNode) {
        if (currentNode) {
            leftStack.push(currentNode);
            currentNode = currentNode->left;
        } else {
            TreeNode* node = leftStack.top();
            if (node->right && !visited[node->right]) {
                currentNode = node->right;
            } else {
                leftStack.pop();
                ans.push_back(node->val);
                visited[node] = true;
            }
        }
    }
    
    return ans;
}
