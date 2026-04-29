class Solution {
public:
    int fun(int n, int ind, vector<int>& dp){
        if(ind==n) return 1;
        if(ind>n) return 0;
        if(dp[ind]!=-1) return dp[ind];
        return dp[ind] = fun(n, ind+1, dp) + fun(n, ind+2, dp);
    }

    int climbStairs(int n) {
        vector<int> dp(n, -1);
        return fun(n, 0, dp);
    }
};
