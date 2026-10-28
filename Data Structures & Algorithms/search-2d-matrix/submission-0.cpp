class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool ret = false;
        int l = 0;
        int r = matrix[0].size() - 1;
        for (auto& row : matrix) {
            if (row[l] <= target && row[r] >= target) {
                while (l <= r) {
                    int m = l + (r - l) / 2;
                    if (row[m] == target) {
                        ret = true;
                        goto out;
                    } else if (row[m] < target) {
                        l = m + 1;
                    } else {
                        r = m - 1;
                    }
                }
            }
        }
        out:
            return ret;
    }
};
