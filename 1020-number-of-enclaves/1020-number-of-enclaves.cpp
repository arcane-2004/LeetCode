class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited(m, vector<int> (n, 0));
        queue<pair<int, int>> q;

        for(int i=0; i<m; i++){
            if(grid[i][0] && !visited[i][0]){
                visited[i][0] = 1;
                q.push({i, 0});
            }

            if(grid[i][n-1] && !visited[i][n-1]){
                visited[i][n-1] = 1;
                q.push({i, n-1});
            }
        }

        for(int i=0; i<n; i++){
            if(grid[0][i] && !visited[0][i]){
                visited[0][i] = 1;
                q.push({0, i});
            }

            if(grid[m-1][i] && !visited[m-1][i]){
                visited[m-1][i] = 1;
                q.push({m-1, i});
            }
        }

        while(!q.empty()){

            auto top = q.front();
            q.pop();

            int row = top.first;
            int col = top.second;

            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};

            for(int i=0; i<4; i++){
                int newR = row + dx[i];
                int newC = col + dy[i];

                if(newR >= 0 && newR < m && newC >= 0 && newC < n){
                    if(grid[newR][newC] && !visited[newR][newC]){
                        visited[newR][newC] = 1;
                        q.push({newR, newC});
                    }
                }
            }
        }


        int ans=0; 
        for(int i=1; i<m-1; i++){
            for(int j = 1; j<n-1; j++){
                if(grid[i][j] && !visited[i][j]){
                    visited[i][j] = 1;
                    ans++;
                }
            }
        }

        return ans;
    }
};