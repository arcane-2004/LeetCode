class Solution {

    vector<vector<int>> ans;
    void twoSum(vector<int>& nums, int tg, int n2, int n3){

        while(n2 < n3){
            int sum = nums[n2] + nums[n3];
            if(sum < tg){
                n2++;
            }
            else if(sum > tg){
                n3--;
            }
            else{
                while(n2 < n3 && nums[n2] == nums[n2+1]) n2++;
                while(n2 < n3 && nums[n3] == nums[n3-1]) n3--;

                ans.push_back({-tg, nums[n2], nums[n3]});
                n2++;
                n3--;
            }
        }
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        
        sort(nums.begin(), nums.end());

        for(int i=0; i<n; i++){
            if(i != 0 && nums[i] == nums[i-1]){
                continue;
            }

            int n1 = nums[i];
            int tg = -n1;

            twoSum(nums, tg, i+1, n-1);

        }

        return ans;
    }
};