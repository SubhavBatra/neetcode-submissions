class Solution {
public:
    int fun(int ind, int n, vector<int>& cost){
        if(ind >= n) return 0;
        return cost[ind] + min(fun(ind+1,n,cost), fun(ind+2,n,cost));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        return min(fun(0, n, cost), fun(1, n, cost));
    }
};
