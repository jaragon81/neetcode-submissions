class Solution {
public:
    bool isValid(string s) {
        bool ret = false;
        if (s.size() % 2 == 0) {
            std::stack<char> stck{};
            for (char ch : s) {
                if (ch == '{' || ch == '(' || ch == '[') {
                    stck.push(ch);
                } else if (stck.size() > 0) {
                    auto tmp = stck.top();
                    if (tmp == '{' && ch == '}' ||
                            tmp == '[' && ch == ']' ||
                            tmp == '(' && ch == ')') {
                        stck.pop();
                        continue;
                        }
                    else {
                        break;
                    }
                } else {
                    goto ret;
                }
            }
            if (stck.size() == 0)
                ret = true;
        }
ret:
        return ret;
    }
};
