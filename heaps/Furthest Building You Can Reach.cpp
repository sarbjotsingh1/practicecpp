// https://leetcode.com/problems/furthest-building-you-can-reach/

/*
Problem:
You are given an integer array heights representing the heights of buildings, some bricks, and some ladders.
You start your journey from building 0 and move to the next building by possibly using bricks or ladders.
While moving from building i to building i+1 (0-indexed),
i) If the current building's height is greater than or equal to the next building's height, you do not need a ladder or bricks,
ii) If the current building's height is less than the next building's height, you can either use one ladder or (h[i+1] - h[i]) bricks.
Return the furthest building index (0-indexed) you can reach if you use the given ladders and bricks optimally.
*/

/*
Explanation:
It's always optimal to use ladders in the largest jumps.
Heap pq store k height difference that we need to use ladders.
Each move, if the height difference d > 0,
we push d into the priority queue pq.
If the size of queue exceed ladders, it means we have to use bricks for one move.
Then we pop out the smallest difference, and reduce bricks.
If bricks < 0, we can't make this move, then we return current index i.
If we can reach the last building, we return n - 1.
*/

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        for (int i = 0; i < n - 1; i++) {
            int d = heights[i + 1] - heights[i];
            if (d > 0)
                minHeap.push(d); // minHeap = reverse maxHeap
            if (minHeap.size() > ladders) {
                bricks -= minHeap.top();
                minHeap.pop();
            }
            if (bricks < 0)
                return i;
        }
        return n - 1;
        
    }
};
