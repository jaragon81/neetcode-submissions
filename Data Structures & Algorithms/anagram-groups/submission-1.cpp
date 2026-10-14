class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::vector<std::string> strs_cpy = strs;
        for (auto& str : strs_cpy) {
            std::sort(str.begin(), str.end());
        }

        std::unordered_map<std::string, std::vector<size_t>> mp{};
        for (size_t i = 0; i < strs_cpy.size(); ++i) {
            mp[strs_cpy[i]].push_back(i);
        }

        std::vector<std::vector<std::string>> ret{};
        for (auto [first, second] : mp) {
            std::vector<std::string> tmp{};
            for (int idx : second) {
                tmp.push_back(strs[idx]);
            }
            ret.push_back(tmp);
        }
        return ret;
    }
};
