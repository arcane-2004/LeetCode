class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int n = s.length();
        int m = t.length();
        int cnt = 0;

        int i=0, j = 0;
        while(i < n && j < m){
            if(s[i] == t[j]){
                i++;
                j++;
                cnt++;
            }
            else{
                j++;
            }
        }

        if(cnt == n){
            return true;
        }
        return false;
    }
};