//Problem link : https://leetcode.com/problems/unique-binary-search-trees/

// Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.

//Solution

class Solution {
public:
    int dp[30];
    int numTrees(int n) {
        dp[0] = dp[1] = 1;
        dp[2] = 2;
        for(int i =3; i <= n;i++) { // i represents the number of nodes
            for(int j = 1; j <=i ;j++) { // root the tree at node j , j is between [1,i]
				// the number of ways 
				// is the number of ways for the left subtree times the number of ways for the right sub tree (the rule of product) 
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};
