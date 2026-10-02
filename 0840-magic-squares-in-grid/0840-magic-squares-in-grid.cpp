class Solution {

    bool check(vector<vector<int>>& grid, int r, int c){

        unordered_set<int> st;
        for(int i = r; i < r+3; i++){
            for(int j = c; j < c+3; j++){
                if(grid[i][j] < 1 || grid[i][j] > 9 || st.count(grid[i][j])){
                    return false;
                }
                else{
                    st.insert(grid[i][j]);
                }
            }
        }

        int sum = grid[r][c] + grid[r][c+1] + grid[r][c+2];

        for(int i=r; i < r+3; i++){
            if((grid[i][c] + grid[i][c+1] + grid[i][c+2]) != sum){
                return false;
            }
        }

        for(int i=c; i < c+3; i++){
            if((grid[r][i] + grid[r+1][i] + grid[r+2][i]) != sum){
                return false;
            }
        }

        if((grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2]) != sum){
            return false;
        }

        if((grid[r][c+2] + grid[r+1][c+1] + grid[r+2][c]) != sum){
            return false;
        }

        return true;
    }
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        
        int row = grid.size();
        int col = grid[0].size();

        int cnt = 0;

        for(int i=0; i<row-2; i++){
            for(int j = 0; j<col-2; j++){

                if(check(grid, i, j)){
                    cnt++;
                }
            }
        } 

        return cnt;
    }
};