
 //  Copyright © 2021 Kiran. All rights reserved.
 // 
 //  Problem Statement:
 //  https://www.interviewbit.com/problems/inorder-traversal/
 //  
 //  Given a binary tree, return the inorder traversal of its nodes values. Using recursion is not allowed.
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
vector<int> inorderTraversalOLD(TreeNode* A) {
    // Left, Current, Right.
    vector<int> solutionVector;
    int n = 0, value;
    
    stack<TreeNode*> stack1;
    set<TreeNode*> nodeVisited;
    stack1.push(A);
    
    while (!stack1.empty()) {
        TreeNode* node = stack1.top();
        
        value = node->val;
        TreeNode* l = node->left;
        TreeNode* r = node->right;

        if (l) {
            
            if (nodeVisited.find(l) == nodeVisited.end()) {
                // Left is not visited. Add left node.
                stack1.push(l);
                continue;
            } else {
                // Left is already visited.
                
                // Process current node.
                solutionVector.push_back(value);
                nodeVisited.insert(stack1.top());
                stack1.pop();
                
                // Add right node.
                if (r) { stack1.push(r); }

                continue;
            }
            
        }
        
        solutionVector.push_back(value);
        nodeVisited.insert(stack1.top());
        stack1.pop();
        
        // Add right node.
        if (r) { stack1.push(r); }

        // if (!l) {
        //     // Append to ans.
        //     solutionVector.push_back(value);
        //     stack1.pop();
        //     n++;

        //     if (!r) {
        //         // stack1.pop();
        //     } else {
        //         stack1.push(r);
        //     }
        // }
        // else {
        //     stack1.push(l);
        //     continue;
        // }
        
        
    }
    
    return solutionVector;
}
vector<int> Solution::inorderTraversal(TreeNode* A) {
    
    
    vector<int> solution_vector;
    TreeNode* currentNode = A;
    stack<TreeNode*> stack;
    
    while(!stack.empty() || currentNode) {
        if (currentNode) {
            stack.push(currentNode);
            currentNode = currentNode->left;
        } else {
            TreeNode* node = stack.top();
            solution_vector.push_back(node->val);
            stack.pop();
            currentNode = node->right;
            
        }
    }
    
    return solution_vector;
}
