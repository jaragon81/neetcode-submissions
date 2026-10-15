class Solution {
public:
    bool isPalindrome(string s) {
        bool ret = true;
        for (size_t i = 0, j = s.size() - 1; i < j; ) {
            if (std::isalnum(s[i]) == 0) {
                ++i;
                continue;
            }
            if (std::isalnum(s[j]) == 0) {
                --j;
                continue;
            }
                
            if (std::tolower(s[i]) != std::tolower(s[j])) {
                ret = false;
                break;
            }
            ++i;
            --j;

        }
        return ret;
    }
};
