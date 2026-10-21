class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> ret(nums.size(), 0);
        if(std::count(nums.begin(), nums.end(), 0) < 2) {
            auto product = std::accumulate(nums.begin(), nums.end(), 1, std::multiplies<int>{});
            for (size_t i = 0; i < nums.size(); ++i) {
                if (nums[i] == 0) {
                    int acc = 1;
                    for (size_t j = 0; j < nums.size(); ++j) {
                        if (j != i)
                            acc *= nums[j];
                        else
                            continue;
                    }
                    ret[i] = acc;
                } else {
                    ret[i] = product / nums[i];
                }
            }
        }

        return ret;
    }
};
