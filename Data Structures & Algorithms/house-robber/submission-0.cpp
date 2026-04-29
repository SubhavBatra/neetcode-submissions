class Solution {
public:
    int fun(int ind, vector<int>& nums, vector<int>& dp){
        if(ind>=nums.size())return 0;
        if(dp[ind]!=-1) return dp[ind];
        return dp[ind] = max(fun(ind+1, nums, dp), nums[ind]+fun(ind+2, nums, dp));
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return fun(0, nums, dp);
    }
};
