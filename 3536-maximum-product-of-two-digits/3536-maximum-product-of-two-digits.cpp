class Solution {
public:
    int maxProduct(int n) {
        
        vector<int> arr;
        while(n != 0){
            int d = n%10;
            n = n/10;

            arr.push_back(d);
        }

        sort(arr.begin(), arr.end());
        int l = arr.size();

        int ans = arr[l-1] * arr[l-2];

        return ans;

    }
};