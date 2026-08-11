class Solution {
    vector<vector<int>> ans;

    void solve(vector<int>& nums, int tg, int i, int j){
        while(i < j){
            int sum = nums[i] + nums[j];
            if(sum > tg) j--;
            else if(sum < tg) i++;


            else{
                while(i < j && nums[j] == nums[j-1]) j--;
                while(i < j && nums[i] == nums[i+1]) i++;
                ans.push_back({-tg, nums[i], nums[j]});
                i++;
                j--;
            }

        }
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for(int i=0; i<n; i++){

            int n1 = nums[i];
            int tg = -n1;

            if(i !=0 && nums[i] == nums[i-1]) continue;

            solve(nums, tg, i+1, n-1);
        }

        return ans;
    }
};