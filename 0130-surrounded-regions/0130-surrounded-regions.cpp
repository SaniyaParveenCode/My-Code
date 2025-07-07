class Solution {
public:
    void convert(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == 'B') {
                    board[i][j] = 'O';
                } else if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }

    bool isValid(int i, int j, int n, int m, vector<vector<char>>& board) {
        return i >= 0 && i < n && j >= 0 && j < m && board[i][j] == 'O';
    }

    void dfs(vector<vector<char>>& board, int i, int j, int n, int m) {
        board[i][j] = 'B';
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        for(int d = 0; d < 4; d++) {
            int ni = i + dx[d];
            int nj = j + dy[d];
            if(isValid(ni, nj, n, m, board)) {
                dfs(board, ni, nj, n, m);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if(n == 0) return;
        int m = board[0].size();

        // Check first and last column
        for(int i = 0; i < n; i++) {
            if(board[i][0] == 'O') dfs(board, i, 0, n, m);
            if(board[i][m - 1] == 'O') dfs(board, i, m - 1, n, m);
        }

        // Check first and last row
        for(int j = 0; j < m; j++) {
            if(board[0][j] == 'O') dfs(board, 0, j, n, m);
            if(board[n - 1][j] == 'O') dfs(board, n - 1, j, n, m);
        }

        convert(board);
    }
};
