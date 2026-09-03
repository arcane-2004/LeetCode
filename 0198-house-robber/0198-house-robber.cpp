class Solution {

    int solve(int n, vector<int>& nums, vector<int> &dp){
        if(n < 0){
            return 0;
        }

        if(dp[n] != -1){
            return dp[n];
        }

        int take = nums[n] + solve(n-2, nums, dp);
        int notTake = 0 + solve(n-1, nums, dp);

        return dp[n] = max(take, notTake); 
    }

public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        // vector<int> dp(n, -1);
        // dp[0] = nums[0];

        int prev1 = 0;
        int prev = nums[0];

        // for(int i=1; i<n; i++){
        //     int take = nums[i];
        //     if(i > 1){
        //         take += dp[i-2];
        //     }

        //     int notTake = 0 + dp[i-1];

        //     dp[i] = max(take, notTake);
        // }

        for(int i=1; i<n; i++){

            int take = nums[i] + prev1;
            int notTake = prev;

            int curr = max(take, notTake);

            prev1 = prev;
            prev = curr;
        }

        return prev;

        // return solve(n-1, nums, dp);

        // return dp[n-1];
    }
};