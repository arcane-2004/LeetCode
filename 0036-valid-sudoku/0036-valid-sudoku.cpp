class Solution {
    bool gridCheck(int i, int j, vector<vector<char>>& board){
        unordered_map<char, bool> mp;

        for(int row=i; row < i+3; row++){
            for(int col=j; col < j+3; col++){
                if(mp[board[row][col]]){
                    return false;
                }
                else if(board[row][col] != '.' ){
                    mp[board[row][col]] = 1;
                }
                
            }
        }

        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        // check row and col
        for(int row=0; row<9; row++){
            unordered_map<char, bool> mp;
            for(int col =0; col<9; col++){
                if(mp[board[row][col]]){
                    return false;
                }
                else if(board[row][col] != '.' ){
                    mp[board[row][col]] = 1;
                }
            }
        }

        for(int col=0; col<9; col++){
            unordered_map<char, bool> mp;
            for(int row =0; row<9; row++){
                if(mp[board[row][col]]){
                    return false;
                }
                else if(board[row][col] != '.' ){
                    mp[board[row][col]] = 1;
                }
            }
        }

        for(int i=0; i<9; i += 3){
            for(int j=0; j<9; j+= 3){
                bool check = gridCheck(i, j, board);
                if(!check){
                    return false;
                }
            }
        }
        

        return true;

    }
};