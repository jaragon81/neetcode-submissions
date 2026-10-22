class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        std::vector<std::pair<int, int>> tmp{};
        for (size_t i = 0; i < position.size(); ++i) {
            tmp.emplace_back(position[i], speed[i]);
        }
        std::sort(tmp.begin(), tmp.end(), [](auto& lhs, auto& rhs) {return rhs.first < lhs.first;});
        std::stack<float> ret{};
        for (auto el : tmp) {
            float time = static_cast<float>(target - el.first) / el.second;
            if (ret.empty()) {
                ret.push(time);
            } else {
                auto top = ret.top();
                if (time > top) {
                    ret.push(time);
                }
            }
        }
        return ret.size();
    }
};
