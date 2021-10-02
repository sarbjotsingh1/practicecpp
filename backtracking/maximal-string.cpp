//  Copyright © 2021 Gurwinder Singh. All rights reserved.
// 
//  Problem Statement:
//  https://www.interviewbit.com/problems/maximal-string/
//  
//  Find multiple missing elements in a sorted array.
//


string maxNum;

void swapAndGetMax(string A, int k) {
    if (k <= 0) return;
    string currentMaxNum = A;
    for(int i = 0; i < A.length() - 1; i++) {
        for(int j = i+1; j < A.length(); j++) {
            string tempA = A;
            char tempChar = tempA[i];
            tempA[i] = tempA[j];
            tempA[j] = tempChar;

            if (stoi(maxNum) < stoi(tempA)){
                maxNum = tempA;
            }

            swapAndGetMax(tempA, k-1);
        }
    }
}
string Solution::solve(string A, int B) {
    maxNum = A;
    swapAndGetMax(A, B);

    return maxNum;
}
