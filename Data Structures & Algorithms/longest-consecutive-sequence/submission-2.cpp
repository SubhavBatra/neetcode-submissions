class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st(nums.begin(), nums.end());
        int ans=0; int len = 0;
        for(auto it: st){
            if(st.find(it-1)==st.end()){
                len=1;
                while(st.find(it+len)!=st.end()){
                    len++;
                }
                ans=max(ans, len);
            }
        }
        return ans;
    }
};
