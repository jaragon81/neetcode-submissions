class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (size_t i = 0; i < board.size(); ++i) {
            std::unordered_map<char, int> rows{};
            for (auto row_el : board[i]) {
                if (std::isdigit(row_el)) rows[row_el]++;
            }
            if (std::any_of(rows.begin(), rows.end(),
                            [](auto map_el) { return map_el.second > 1; }))
                return false;

            std::unordered_map<char, int> colums{};
            for (size_t j = 0; j < board.size(); ++j) {
                if (std::isdigit(board[j][i])) colums[board[j][i]]++;
            }
            if (std::any_of(colums.begin(), colums.end(),
                            [](auto map_el) { return map_el.second > 1; }))
                return false;
        }

        for (size_t square = 0; square < board.size(); ++square) {
            std::unordered_map<char, int> sqrs;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int row = (square / 3) * 3 + i;
                    int col = (square % 3) * 3 + j;
                    if (std::isdigit(board[row][col])) sqrs[board[row][col]]++;
                }
            }
            if (std::any_of(sqrs.begin(), sqrs.end(),
                            [](auto map_el) { return map_el.second > 1; }))
                return false;
        }
        return true;
    }
};
