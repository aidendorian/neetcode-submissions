class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> rows(9, vector(9, false));
        vector<vector<bool>> columns(9, vector(9, false));
        vector<vector<bool>> sub(9, vector(9, false));
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                char current = board[i][j];
                if(current=='.')
                    continue;
                int global_idx = current-'0'-1;
                int sub_idx = (i/3)*3 + (j/3);
                if (rows[i][global_idx] || columns[j][global_idx] || sub[sub_idx][global_idx])
                    return false;
                rows[i][global_idx] = true;
                columns[j][global_idx] = true;
                sub[sub_idx][global_idx] = true;
            }
        }
        return true;
    }
};