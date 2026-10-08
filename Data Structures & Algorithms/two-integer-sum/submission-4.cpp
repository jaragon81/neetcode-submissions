class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret{};
        for (size_t i = 0; i < nums.size() - 1; ++i) {
            for (size_t j = i + 1; j < nums.size(); ++j) {
                if (nums[j] == (target - nums[i])) {
                    ret.push_back(i);
                    ret.push_back(j);
                    return ret;                 
                }
            }
        }
    }
};
