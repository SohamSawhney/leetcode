class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // If start or end is blocked
        if (grid[0][0] != 0 || grid[n-1][n-1] != 0) return -1;
        
        // If single cell and it's open
        if (n == 1) return 1;

   
        int drow[8] = {-1,-1,-1,0,0,1,1,1};
        int dcol[8] = {-1,0,1,-1,1,-1,0,1};

        queue<pair<int,int>> q;
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        
        dist[0][0] = 1; // start length = 1
        q.push({0,0});

        while (!q.empty()) {
            auto [r, c] = q.front(); 
            q.pop();

            for (int i = 0; i < 8; i++) {
                int nr = r + drow[i];
                int nc = c + dcol[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n 
                    && grid[nr][nc] == 0 
                    && dist[r][c] + 1 < dist[nr][nc]) {
                    
                    dist[nr][nc] = dist[r][c] + 1;

                    // reached destination
                    if (nr == n-1 && nc == n-1) 
                        return dist[nr][nc];

                    q.push({nr, nc});
                }
            }
        }
        return -1;
        
    }
};
