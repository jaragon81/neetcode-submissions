class Solution {
public:
    int characterReplacement(string s, int k) {
        auto l = 0;
        auto r = 0;
        int ret = 0;
        std::array<int, 26> chars{};
        while (r < s.size()) {
            chars[s[r] - 'A']++;
            int max_val = -1;
            for(int i = 0; i < 26; ++i) {
                if (chars[i] > max_val) {
                    max_val = chars[i];
                }
            }
            if ((r - l + 1 - max_val) <= k) {
                ret = std::max(ret, r - l + 1);
                r++;
            } else {
                chars[s[l] - 'A']--;
                chars[s[r] - 'A']--;
                l++;
            }
        }
        return ret;
    }
};
