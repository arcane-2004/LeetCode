class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        

        for(int i=0; i<n; i++){
            if(i == 0){
                ans[i] = 1;
            }

            else{
                ans[i] = ans[i-1] * nums[i-1];
            }
        }

        int rp = 1;
        for(int i=n-1; i>=0; i--){
            if(i == n-1){
                continue;
            }

            else{
                rp = rp * nums[i+1];
                ans[i] = ans[i] * rp;
            }
        }

        return ans;
    }
};