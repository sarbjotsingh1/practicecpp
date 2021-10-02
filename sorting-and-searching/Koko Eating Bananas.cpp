// https://leetcode.com/problems/koko-eating-bananas/

/*
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.
Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. 
If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.
Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
Return the minimum integer k such that she can eat all the bananas within h hours.
*/


class Solution {
public:
    bool check(int mid, int H, vector<int>& piles) {
        int total = 0;
        for (int p: piles) {
            total += (p + mid - 1) / mid;
        }

        return total <= H;
    }
    
    int minEatingSpeed(vector<int>& piles, int H) {
        int lo = 1;
        int hi = *max_element(piles.begin(), piles.end());
        
        while (lo < hi) {
            int mid = (lo + hi) / 2;

            if (check(mid, H, piles))
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo;
    }
};
