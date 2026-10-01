class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        
        if(s.length() != t.length()) return false;

        vector<int> arr(27, 0);
        int d = k / 26;
        int r = k % 26;

        for(int i=0; i<27; i++){
            arr[i] += d;
        }

        for(int i=0; i<r+1; i++){
            arr[i]++;
        }

        int n = s.length();
        for(int i=0; i<n; i++){
            if(s[i] < t[i]){
                int sub = t[i] - s[i];
                if(arr[sub] == 0) return false;
                else{
                    arr[sub]--;
                }
            }
            else if(s[i] > t[i]){
                int sub = t[i] - s[i] + 26;
                if(arr[sub] == 0) return false;
                else{
                    arr[sub]--;
                }
            }
            else{
                continue;
            }
        }

        return true;
    }
};