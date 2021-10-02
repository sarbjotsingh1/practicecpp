//  Copyright © 2021 Gurwinder Singh. All rights reserved.
// 
//  Problem Statement:
//  https://www.interviewbit.com/problems/permutations/
//  
//  Given a collection of numbers, return all possible permutations.
//

void populateSolutions(vector<int> &A, vector<int> &index_vec, vector<vector<int> > &solution_vec) {

    if (index_vec.size() >= A.size()) {

        vector<int> temp_vec;
        // cout << "\nFinished with: ";
        for(auto index: index_vec) {
            // cout << " " << A[index];
            temp_vec.push_back(A[index]);
        }
        // cout << endl;
        
        solution_vec.push_back(temp_vec);
        return;
    }

    for (int i = 0; i < A.size(); i++) {
        // If i not in index_vec
        if ( find(index_vec.begin(), index_vec.end(), i) == index_vec.end()){
            index_vec.push_back(i);
            // cout << " in " << i;
            populateSolutions(A, index_vec, solution_vec);
            // cout << " out " << i;
            index_vec.pop_back();
        }
    }
}
vector<vector<int> > Solution::permute(vector<int> &A) {
    vector<int> index_vec;
    vector<vector<int> > solution_vec;
    sort(A.begin(), A.end());

    populateSolutions(A, index_vec, solution_vec);

    return solution_vec;
}
