class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int n = nums.size();

        int i = 0;
        int j = i;
        
        while(j < n-1){

            while(i < n-1 && nums[i] != 0){
                i++;
            }
            
            j = i;
            while(j < n-1 && nums[j] == 0){
                j++;
            }

            if(nums[i] == 0 && nums[j] != 0){
                swap(nums[i], nums[j]);
            }
        }

    }
};