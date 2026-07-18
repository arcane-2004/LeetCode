class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<pair<int, int>, int>> q;

        int time = 0;
        int fresh = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                }

                else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        while(!q.empty()){
            auto top = q.front();
            q.pop();

            int row = top.first.first;
            int col = top.first.second;
            int t = top.second;
            time = max(time, t);

            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};

            for(int i=0; i<4; i++){
                int newRow = row + dx[i];
                int newCol = col + dy[i];

                if(newRow >= 0 && newRow < m && newCol >= 0 && newCol < n){
                    if(grid[newRow][newCol] == 1){
                        grid[newRow][newCol] = 2;
                        q.push({{newRow, newCol}, t+1});
                        fresh--;
                    }
                }
            }
        }

        if(fresh != 0){
            return -1;
        }

        return time;
    }
};