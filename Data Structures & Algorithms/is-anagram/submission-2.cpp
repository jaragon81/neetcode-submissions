class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char, int> s_mp{};
        for (char ch : s) {
            s_mp[ch]++;
        }
        std::unordered_map<char, int> t_mp;
        for (char ch : t) {
            t_mp[ch]++;
        }

        return s_mp == t_mp;
    }
};
