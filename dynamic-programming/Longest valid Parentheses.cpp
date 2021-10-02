// Practice Coding Questions in Cpp
// Problem Statement:Longest valid Parentheses 

// Sources:
// GeekForGeeks (https://www.geeksforgeeks.org/)


#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int maxLength(string S){
         int res = 0;
        
        int open = 0;
        int close = 0;
        
        for(int i = 0; i < S.size(); i++)
        {
            if(S[i] == '(')
            {
                open++;
            }
            else
            {
                close++;
            }
            
            if(open == close)
            {
                res = max(res, 2 * open);
            }
            else if(close > open)
            {
                open = close = 0;
            }
        }
        
        open = close = 0;
        
        for(int i = S.size() - 1; i >= 0; i--)
        {
            if(S[i] == '(')
            {
                open++;
            }
            else
            {
                close++;
            }
            
            if(open == close)
            {
                res = max(res, 2 * open);
            }
            else if(open > close)
            {
                open = close = 0;
            }
        }
        
        return res;
        // code here
    }
};

int main()
{
  int t;
  cin>>t;
  while(t--){
    string S;
    cin>>S;
    Solution ob;
    cout<<ob.maxLength(S)<<"\n";
  }
  return 0;
}
