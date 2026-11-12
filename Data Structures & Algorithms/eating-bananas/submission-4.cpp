class Solution {
   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *std::max_element(piles.begin(), piles.end());
        while (l <= r) {
            int m = (r - l) / 2 + l;
            long long sum = 0;
            for (auto el : piles) {
                sum += ((el + m - 1) / m);
            }
            if (sum > h) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return l;
    }
};
