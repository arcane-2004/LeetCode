class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        
        vector<int> arr1;
        vector<int> arr2;

        int i=0, j=0;

        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        for(int it = 2; it<nums.size(); it++){
            if(arr1[i] > arr2[j]){
                arr1.push_back(nums[it]);
                i++;
            }
            else{
                arr2.push_back(nums[it]);
                j++;
            }
        }
      
        arr1.insert(arr1.end(), arr2.begin(), arr2.end());

        return arr1;
    }
};