class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        int time = 0;
        int fresh = 0;
        queue<pair<pair<int, int>, int>> q;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){

                if(grid[i][j] == 2){
                    q.push({{i,j}, 0});
                }

                if(grid[i][j] == 1){
                    fresh++;
                }

            }
        }


        while(!q.empty()){
            auto top = q.front();
            int row = top.first.first;
            int col = top.first.second;
            int t = top.second;
            time = max(t, time);
            q.pop();

            //URDL
            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};
            
            
            for(int i=0; i<4; i++){
                
                int newRow = row + dx[i];
                int newCol = col + dy[i];

                if(newRow >= 0 && newRow < m && newCol >= 0 && newCol < n){
                    if(grid[newRow][newCol] == 1){
                        q.push({{newRow, newCol}, t+1});
           
                        grid[newRow][newCol] = 2;

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