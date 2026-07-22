class Solution {
    int solve(vector<int> &cost, int n, vector<int> &arr){

        if(n==0) return cost[0];
        if(n == 1) return cost[1];

        if(arr[n] != -1){
            return arr[n];
        }
        arr[n] = cost[n] + min(solve(cost, n-1, arr), solve(cost, n-2, arr));
        return arr[n];
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> arr(n+1, -1);
        int ans = min(solve(cost, n-1, arr),  solve(cost, n-2, arr));
        return ans;
    }
};