class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size();
        int l=0, r=n-1;
        while(l<r and ans.size()!=2){
            if(nums[l]+nums[r]==target){
                ans = {l+1,r+1};
            }
            if(nums[l]+nums[r] > target){
                r--;
            }
            else if(nums[l]+nums[r]<target){
                l++;
            }
        }
        return ans;
    }
};
