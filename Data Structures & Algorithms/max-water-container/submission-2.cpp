class Solution {
   public:
    int maxArea(vector<int>& heights) {
        int ret = 0;
        for (int i = 0, j = heights.size() - 1; j > i; ) {
            int area = (j - i) * std::min(heights[i], heights[j]);
            ret = std::max(ret, area);
            if (heights[i] < heights[j]) {
                i++;
            } else {
                j--;
            }
        }
        return ret;
    }
};
