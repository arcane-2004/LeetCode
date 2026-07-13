
class Solution {

    void bfs(int row, int col, vector<vector<int>> &visited, vector<vector<char>>& grid){
        queue<pair<int, int>> q;

        visited[row][col] = 1;
        q.push(make_pair(row, col));
        int n = grid.size();
        int m = grid[0].size();

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            //URLD
            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};

            for(int k = 0; k < 4; k++) {
                int newRow = row + dx[k];
                int newCol = col + dy[k];

                if(newRow >= 0 && newRow < n &&
                newCol >= 0 && newCol < m) {

                    if(grid[newRow][newCol] == '1' && visited[newRow][newCol] == 0){
                        q.push(make_pair(newRow, newCol));
                        visited[newRow][newCol] = 1;
                    }
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited (n, vector<int>(m, 0));

        int cnt = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1' && visited[i][j] == 0){
                    cnt++;
                    bfs(i, j, visited, grid);
                }
            }
        }

        return cnt;
    }
};