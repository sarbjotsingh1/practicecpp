
// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

/*
A conveyor belt has packages that must be shipped from one port to another within days days.
The ith package on the conveyor belt has a weight of weights[i]. 
Each day, we load the ship with packages on the conveyor belt (in the order given by weights). 
We may not load more weight than the maximum weight capacity of the ship.
Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.
*/


class Solution {
public:
    bool check(int mid, int days, vector<int>& weights) {
        int n = weights.size();
        int cnt = 0, sum = 0;
        for(int i = 0; i < n; i++) {
            if(sum + weights[i] > mid) {
                cnt++;
                sum = 0;
            }
            sum += weights[i];
        }
        // if currently i have some sum, then i require one more day
        if(sum) cnt++;

        return cnt <= days;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int lo =  *max_element(weights.begin(), weights.end());
        int hi = accumulate(weights.begin(), weights.end(), 0);

        while(lo < hi) {
            int mid = (lo + hi) / 2;
            
            if(check(mid, days, weights)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
};
