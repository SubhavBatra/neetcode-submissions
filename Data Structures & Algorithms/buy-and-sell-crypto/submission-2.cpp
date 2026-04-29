class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0; int buy = INT_MAX; int ans = 0;
        for(int i=0;i<n;i++){
            buy = min(buy, prices[i]);
            profit = prices[i]-buy;
            ans = max(ans, profit);
        }
        return ans;
    }
};
