class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int l = 0, r = 0;
        long ans = 0;
        long oriSum = 0;

        while(r < n){
            
            long cnt = r-l+1;
            long winSum = cnt * nums[r];
            oriSum += nums[r];
            long operations = winSum - oriSum;

            while(operations > k){
                oriSum -= nums[l];
                l++;
                cnt--;
                operations = (cnt * nums[r]) - oriSum;
            }

            

            ans = max(ans, cnt);
            r++;


        }

        return ans;
    }
};