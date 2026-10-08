class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_map<int, int> mp{};
        for (auto num : nums) {
            mp[num]++;
        }
        return std::any_of(mp.begin(), mp.end(), [](auto elem) {
            return elem.second > 1;
        });
    }
};