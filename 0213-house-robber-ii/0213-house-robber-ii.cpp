class Solution {

    int solve(int i, vector<int> &temp, vector<int> &dp){

        if(i == 0){
            return temp[0];
        }

        if(i < 0){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }

        int take = temp[i] + solve(i-2, temp, dp);
        int notTake = 0 + solve(i-1, temp, dp);

        return dp[i] = max(take, notTake);
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

        vector<int> dp1(n-1, -1);
        vector<int> dp2(n-1, -1);
        return max(solve(n-2, temp1, dp1), solve(n-2, temp2, dp2));
    }
};