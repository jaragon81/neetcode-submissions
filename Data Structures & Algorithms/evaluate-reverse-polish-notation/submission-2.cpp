class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> stck{};
        for (auto token : tokens) {
            if (token != "+" && token != "-" &&
                token != "*" && token != "/") {
                    stck.push(std::stoi(token));
            } else {
                int opr1 = stck.top();
                stck.pop();
                int opr2 = stck.top();
                stck.pop();
                if (token == "+")
                    stck.push(opr1 + opr2);
                else if (token == "-")
                    stck.push(opr2 - opr1);
                else if (token == "*")
                    stck.push(opr1 * opr2);
                else if (token == "/")
                    stck.push(opr2 / opr1);
            }
        }
        return stck.top();
    }
};
