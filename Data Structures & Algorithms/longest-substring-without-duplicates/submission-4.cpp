class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        std::unordered_set<char> st{};
        int ret;
        if (s.size() >= 1) {
            st.insert(s[l]);
            ret = 1;
        } else {
            ret = 0;
        }
        for (int r = 1; r < s.size() ; ++r) {
            if (st.find(s[r]) == st.end()) {
                st.insert(s[r]);
            } else {
                while (st.size() > 0 && s[r] != s[l]) {
                    st.erase(s[l]);
                    l++;
                }
                st.erase(s[l]);
                l++;
                st.insert(s[r]);
            }
            ret = std::max(ret, static_cast<int>(st.size()));
        }
        return ret;
    }
};
