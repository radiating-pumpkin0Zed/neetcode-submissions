class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;
        int fresh = 0;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 1) fresh++;
                else if(grid[r][c] == 2) q.push({r, c});
            }
        }
        
        int minutes = 0;
        int dirs[5] = {-1, 0, 1, 0, -1};

        while (fresh > 0 && !q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto [r, c] = q.front();
                q.pop();

                for (int d =0; d < 4; d++) {
                    int nr = r + dirs[d];
                    int nc = c + dirs[d+1];

                    if (nr >= 0 && nc >= 0 && nr < m && nc < n && grid[nr][nc]==1) {
                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                        fresh--;
                    }
                }
            }
        minutes++;
        }

        return fresh == 0 ? minutes : -1;
    }
};
