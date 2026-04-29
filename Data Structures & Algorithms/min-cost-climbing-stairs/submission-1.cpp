class Solution {
public:
    int fun(int ind, int n, vector<int>& cost, vector<int>& dp){
        if(ind >= n) return 0;
        if(dp[ind]!=-1) return dp[ind];
        return dp[ind] = cost[ind] + min(fun(ind+1,n,cost, dp), fun(ind+2,n,cost, dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, -1);
        return min(fun(0, n, cost, dp), fun(1, n, cost, dp));
    }
};
