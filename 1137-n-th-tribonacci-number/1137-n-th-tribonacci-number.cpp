class Solution {

    int solve(int n, vector<int>& dp){
        
        if(n <= 0){
            return 0;
        }
        if(n == 1 || n == 2){
            return 1;
        }
        if(dp[n] != -1){
            return dp[n];
        }

        int a = solve(n-1, dp); 
        int b = solve(n-2, dp);
        int c = solve(n-3, dp);
        return dp[n] = a + b + c;
    }
public:
    int tribonacci(int n) {
        // vector<int> dp(n+1, -1);
        
        if(n == 0) return 0;
        else if(n == 1 || n == 2) return 1;

        // dp[0] = 0;
        // dp[1] = 1;
        // dp[2] = 1;

        int prev2 = 0;
        int prev1 = 1;
        int prev = 1;

        for(int i=3; i<n+1; i++){
            // dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
            int curr = prev2 + prev1 + prev;
            prev2 = prev1;
            prev1 = prev;
            prev = curr;
        }
        // return solve(n, dp);
        // return dp[n];

        return prev;
    }
};