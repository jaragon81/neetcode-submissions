class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::stack<std::pair<int, int>> stck{};
        std::vector<int> ret(temperatures.size());
        stck.push({temperatures[0], 0});
        for (size_t i = 1; i < temperatures.size(); ++i) {
            auto top = stck.top();
            if (temperatures[i] <= top.first) {
                stck.push({temperatures[i], i});
            } else {
                while(temperatures[i] > top.first) {
                    ret[top.second] = i - top.second;
                    stck.pop();
                    if (!stck.empty())
                        top = stck.top();
                    else
                        break;
                }
                stck.push({temperatures[i], i});
            }
        }
        return ret;
    }
};
