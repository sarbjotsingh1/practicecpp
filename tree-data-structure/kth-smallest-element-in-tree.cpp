
//  Copyright © 2021 Kiran. All rights reserved.
// 
//  Problem Statement:
//  https://www.interviewbit.com/problems/kth-smallest-element-in-tree/
//  
//  Given a binary search tree, write a function to find the kth smallest element in the tree.
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

TreeNode* setKthSmallestNode(TreeNode* A, int &k) {
    // if (k == 0) return A;
    
    if (A == NULL) {
        return NULL;
    }
    
    TreeNode* left = setKthSmallestNode(A->left, k);
    if ( k == 0) {
        // cout << "FOUND Left: " << A->val << endl;
        return left;
    }
    
    // Current Node.
    k--;
    // cout << "Visiting Node: " << A->val << endl;
    if ( k == 0) {
        // cout << "FOUND: " << A->val << endl;
        return A;
    }
    
    return setKthSmallestNode(A->right, k);
}


int Solution::kthsmallest(TreeNode* A, int B) {
    // k = B;
    TreeNode* node = setKthSmallestNode(A, B);

    return node->val;    
}
