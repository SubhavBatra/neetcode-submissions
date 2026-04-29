class Solution {
public:
    void fun(vector<int>& nums, vector<vector<int>>& ans, int target, vector<int>& temp, int ind){
        if(ind==nums.size()){
            if(target==0) ans.push_back(temp);
            return;
        }
        if(nums[ind]<=target){
            temp.push_back(nums[ind]);
            fun(nums, ans, target-nums[ind], temp, ind);
            temp.pop_back();
        }
        fun(nums, ans, target, temp, ind+1);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        vector<int> temp;
        fun(nums, ans, target, temp, 0);
        return ans;
    }
};
