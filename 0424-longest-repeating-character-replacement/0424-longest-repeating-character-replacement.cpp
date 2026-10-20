class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int n = s.size();
        int l = 0, r = 0;
        int arr[26] = {0};
        int maxFreq = INT_MIN;
        int maxLen = 0;

        while(r < n){

            arr[s[r] - 'A']++;
            maxFreq = max(maxFreq, arr[s[r] - 'A']);

            if((r-l+1) - maxFreq > k){
                arr[s[l] - 'A']--;
                l++;
            }

            maxLen = max(maxLen, r-l+1);

            r++;
        }

        return maxLen;
    }
};