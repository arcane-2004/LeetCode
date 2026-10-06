class Solution {

    int solve(int tg, vector<int>& nums, int k, long prefix[]){

        int l = 0;
        int r = tg;
        long freq = 0;
        while(l <=r ){

            int mid = l + (r-l)/2;

            long cnt = tg - mid + 1;
            long winSum = cnt * nums[tg];
            long oriSum = prefix[tg] - prefix[mid] + nums[mid];
            long operations = winSum - oriSum;

            if(k < operations){
                l = mid+1;
            }
            else{
                freq = max(freq, cnt);
                r = mid-1;
            }
        }

        return freq;
    }

public:
    int maxFrequency(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());

        int n = nums.size();
        long prefix[n];
        long sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
            prefix[i] = sum;
        }

        int ans = 0;

        for(int i=0; i<n; i++){
            int freq = solve(i, nums, k, prefix);
            ans = max(ans, freq);    
        }

        return ans;
    }
};