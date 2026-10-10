class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        
        int n = capacity.size();
        vector<int> arr(n);

        int cnt = 0;

        for(int i=0; i<n; i++){
            arr[i] = capacity[i] - rocks[i];
        }

        sort(arr.begin(), arr.end());

        
        int k = 0;
        for(int i=0; i<n; i++){

            if(arr[i] == 0){
                cnt++;
            }

            else{
                additionalRocks -= arr[i];
                if(additionalRocks < 0){
                    return cnt;
                }
                cnt++;
            }
        }

        return cnt;
    }
};