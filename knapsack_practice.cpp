


// Knapsack - https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
// My Solution -- TLE


#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    
    int memArray[1002][1002];
    
    int maxKnapSack(int wt[], int val[], int W, int n) {
        if (W == 0 || n == 0) return 0;
        
        if (memArray[W][n] != -1) return memArray[W][n];
        
        if (wt[n-1] > W) {
            return memArray[W][n-1] = maxKnapSack(wt, val, W, n-1);
        } else {
            memArray[W - wt[n-1]][n-1] = maxKnapSack(wt, val, W - wt[n-1], n-1);
            memArray[W][n-1] = maxKnapSack(wt, val, W, n-1);
            return max( val[n-1] + memArray[W - wt[n-1]][n-1], memArray[W][n-1]);
        }
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    {
        for (int i=0; i<W+2; i++)
            for (int j=0; j<n+2; j++)
                memArray[i][j] = -1;
        
        return maxKnapSack(wt, val, W, n);
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends
