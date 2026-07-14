class Solution {

    void bfs(int row, int col, int curr, int color, vector<vector<int>>& image, vector<vector<int>> &visited){

        queue<pair<int, int>> q;
        int m = image.size();
        int n = image[0].size();

        visited[row][col] = 1;
        image[row][col] = color;
        q.push({row, col});

        while(!q.empty()){

            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            //URDL
            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};

            for(int k=0; k<4; k++){
                int newRow = r + dx[k];
                int newCol = c + dy[k];

                if(newRow >= 0 && newRow < m && newCol >= 0 && newCol < n){
                    if(image[newRow][newCol] == curr && !visited[newRow][newCol]){
                        visited[newRow][newCol] = 1;
                        image[newRow][newCol] = color;
                        q.push({newRow, newCol});
                    }
                }
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int m = image.size();
        int n = image[0].size();
        vector<vector<int>> visited (m, vector<int>(n, 0));

        int curr = image[sr][sc];

    
        bfs(sr, sc, curr, color,image, visited);
         

        return image;
    }
};