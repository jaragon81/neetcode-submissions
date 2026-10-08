class Solution {
public:
    bool isAnagram(string s, string t) {
        bool ret = true;
        std::unordered_map<char, int> s_mp{};
        for (char ch : s) {
            s_mp[ch]++;
        }
        std::unordered_map<char, int> t_mp;
        for (char ch : t) {
            t_mp[ch]++;
        }
        if (s_mp.size() == t_mp.size()) {
            for (auto [first, second] : s_mp) {
                auto tmp = t_mp.find(first);
                if (tmp == t_mp.end() || second != tmp->second) {
                    ret = false;
                    break;
                }
            }
        } else {
            ret = false;
        }
        return ret;
    }
};
