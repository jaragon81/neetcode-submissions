class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }
        std::vector<int> letters(26);
        for (char ch : s1) {
            letters[ch - 'a']++;
        }

        bool ret = false;
        auto  r = s1.size();
        for (size_t l = 0; l <= s2.size() - r; l++) {
            std::string sb = s2.substr(l, r);
            ret = tmp(letters, sb);
            if (ret)
                break;
        }
        return ret;
    }
    bool tmp(std::vector<int> arg1, std::string s1) {
        for (char ch : s1) {
            arg1[ch - 'a']--;
        }
        return std::all_of(arg1.begin(), arg1.end(), [](int el) { return el == 0; });
    }
};
