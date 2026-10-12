class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        int ret = 0;
        if (nums.size() != 0) {
            std::sort(nums.begin(), nums.end());            
            int cnt = 1;
            ret = 1;
            for (size_t i = 0; i < nums.size() - 1; ++i) {
                if (nums[i] == nums[i + 1]) continue;

                if (nums[i + 1] == nums[i] + 1)
                    cnt++;
                else
                    cnt = 1;
                ret = std::max(ret, cnt);
            }
        }

        return ret;
    }
};
