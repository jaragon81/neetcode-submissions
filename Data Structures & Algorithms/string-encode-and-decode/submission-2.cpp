class Solution {
   public:
    string encode(vector<string>& strs) {
        std::string ret{};
        for (auto str : strs) {
            int len = str.size();
            ret += std::to_string(len);
            ret += '#';
            ret += str;
        }
        return ret;
    }

    vector<string> decode(string s) {
        std::vector<std::string> ret{};
        for (size_t i = 0; i < s.size(); ++i) {
            if (std::isdigit(s[i])) {
                std::string len{};
                int del = 0;
                int j = i;
                while (s[j] != '#') {
                    len += s[j];
                    del++;
                    j++;
                }
                ret.push_back(s.substr(i + del + 1, std::stoi(len)));
                i += del + std::stoi(len);
            }
        }
        return ret;
    }
};
