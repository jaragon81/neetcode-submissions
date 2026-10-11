class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> mp{};
        for (auto num : nums) {
            mp[num]++;
        }

        auto comp = [](const std::pair<int, int>& lhs, const std::pair<int, int>& rhs) {
            return lhs.second < rhs.second;
        };

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(comp)>
            pq{};
        for (const auto& elem : mp) {
            pq.emplace(elem.first, elem.second);
        }

        std::vector<int> ret{};
        while (k) {
            ret.push_back(pq.top().first);
            pq.pop();
            k--;
        }

        return ret;
    }
};
