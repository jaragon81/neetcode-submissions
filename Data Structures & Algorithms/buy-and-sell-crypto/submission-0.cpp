class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ret = 0;
        int buy = prices[0];
        for (size_t i = 1; i < prices.size(); ++i) {
            if (prices[i] < buy)
                buy = prices[i];
            else
                ret = std::max (ret, prices[i] - buy);
        }
        return ret;
    }
};
