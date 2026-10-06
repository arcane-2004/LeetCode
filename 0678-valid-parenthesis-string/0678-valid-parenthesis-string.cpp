class Solution {
    int dp[101][101];
    bool solve(string& s, int i, int open){

        if(i >= s.length()){
            if(open == 0) return true;
            else{
                return false;
            }
        }

        if(dp[i][open] != -1){
            return dp[i][open];
        }

        if(s[i] == '('){
            return dp[i][open] = solve(s, i+1, open+1);
        }

        else if(s[i] == '*'){
            bool opt1 = solve(s, i+1, open+1);
            bool opt2 = false;
            if(open > 0){
                opt2 = solve(s, i+1, open-1);
            }
            bool opt3 = solve(s, i+1, open);

            return dp[i][open] = opt1 || opt2 || opt3;
        }

        else{
            if (open == 0) return false;
            return dp[i][open] = solve(s, i+1, open-1);
        }
    }

public:
    bool checkValidString(string s) {
        
        memset(dp, -1, sizeof(dp));
        return solve(s, 0, 0);
    }
};