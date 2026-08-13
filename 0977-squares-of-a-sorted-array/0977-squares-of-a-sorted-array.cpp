class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        int n = nums.size()-1;
        vector<int> ans(n+1);

        int l=0, r=n;

        while(l <= r){
            int left = nums[l] * nums[l];
            int right = nums[r] * nums[r];

            if(left > right){
                ans[n] = left;
                l++;
            }
            else{
                ans[n] = right;
                r--;
            }

            n--;
        }

        return ans;
    }
};