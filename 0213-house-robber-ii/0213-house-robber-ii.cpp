class Solution {

    // int solve(int i, vector<int> &temp, vector<int> &dp){

    //     if(i == 0){
    //         return temp[0];
    //     }

    //     if(i < 0){
    //         return 0;
    //     }
    //     if(dp[i] != -1){
    //         return dp[i];
    //     }

    //     int take = temp[i] + solve(i-2, temp, dp);
    //     int notTake = 0 + solve(i-1, temp, dp);

    //     return dp[i] = max(take, notTake);
    // }

    int solve(vector<int>& temp){
        int n = temp.size();
        // vector<int> dp(n, -1);

        // dp[0] = temp[0];

        int prev = temp[0];
        int prev2 = 0;

        for(int i=1; i<n; i++){

            int take = temp[i] + prev2;
            // if(i > 1){
            //     take += dp[i-2];
            // }

            int notTake = 0 + prev;
            
            int curr = max(take, notTake);
            prev2 = prev;
            prev = curr;
            // dp[i] = max(take, notTake);
        }

        // return dp[n-1];
        return prev;
    }

public:
    int rob(vector<int>& nums) {

        int n = nums.size();

        if(n == 1){
            return nums[0];
        }

        vector<int> temp1;
        vector<int> temp2;
        for(int i=0; i<n; i++){
            if(i != 0) temp1.push_back(nums[i]);
            if(i != n-1) temp2.push_back(nums[i]);
        }

        // vector<int> dp1(n-1, -1);
        // vector<int> dp2(n-1, -1);

        // return max(solve(n-2, temp1, dp1), solve(n-2, temp2, dp2));
        return max(solve(temp1), solve(temp2));
    }
};