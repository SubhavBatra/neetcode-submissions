class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> mp;
        vector<vector<int>> freq(nums.size()+1);
        for(int i: nums){
            mp[i] = 1 + mp[i];
        }
        for(auto& it: mp){
            freq[it.second].push_back(it.first);
        }
        for(int i=freq.size()-1;i>0;i--){
            for(int n: freq[i]){
                ans.push_back(n);
                if(ans.size()==k) return ans;
            }
        }
        return ans;
    }
};
