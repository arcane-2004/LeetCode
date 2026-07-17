class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> ans(m, vector<int> (n, -1));

        queue<pair<int, int>> q;

        for(int i=0; i<m; i++){
            for(int j =0; j<n; j++){
                if(mat[i][j] == 0){
                    q.push({i, j});
                    ans[i][j] = 0;
                }
            }
        }

        while(!q.empty()){
            auto top = q.front();
            q.pop();

            int row = top.first;
            int col = top.second;

            //URDL
            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};

            for(int i=0; i<4; i++){
                int nRow = row + dx[i];
                int nCol = col + dy[i];

                if(nRow >= 0 && nRow < m && nCol >= 0 && nCol < n){
                    if(mat[nRow][nCol] != 0 && ans[nRow][nCol] == -1){
                        ans[nRow][nCol] = ans[row][col] + 1;
                        q.push({nRow, nCol});
                    }
                }
            }
        }

        return ans;
    }
};