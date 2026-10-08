class Solution {

    bool solve(int i, int open, string &s, vector<vector<int>>& dp){

        if(i >= s.length()){
            if(open == 0) return true;
            return false;
        }

        if(dp[i][open] != -1){
            return dp[i][open];
        }

        if(s[i] == '('){
            return dp[i][open] = solve(i+1, open+1, s, dp);
        }

        else if(s[i] == ')'){
            if(open > 0){
                return dp[i][open] = solve(i+1, open-1, s, dp);
            }
            return false;
        }

        else{
            bool opt1 = solve(i+1, open+1, s, dp);
            bool opt2 = solve(i+1, open, s, dp);
            bool opt3 = false;
            if(open > 0){
                opt3 = solve(i+1, open-1, s, dp);
            }

            return dp[i][open] = opt1 | opt2 | opt3 ;
        }
    }

public:
    bool checkValidString(string s) {

        int n = s.length();
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));

        return solve(0, 0, s, dp);
    }
};