class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<string>> mp{};
        for (auto& s : strs) {
            std::string tmp = s;
            sort(tmp.begin(), tmp.end());
            mp[tmp].push_back(s);
        }

        std::vector<std::vector<std::string>> ret{};
        for (auto [first, second] : mp) {
            ret.push_back(second);
        }
        return ret;
    }
};
