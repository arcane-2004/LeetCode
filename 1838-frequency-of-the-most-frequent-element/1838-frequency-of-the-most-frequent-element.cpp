class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int l = 0, r = 0;
        int ans = 0;
        long oriSum = 0;

        while(r < n){
            long cnt = r - l + 1;
            long winSum = nums[r] * cnt;
            oriSum += nums[r];
            long diff = winSum - oriSum;

            if(diff > k){
                oriSum -= nums[l];
                l++;
            }

            ans = max(ans, r-l+1);
            r++;
        }

        return ans;
    }
};