class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int i = 0, j = 0;

        int ones = 0;
        string result = "";

        while(j < n){
            
            if(s[j] == '1'){
                ones++;
            }
            while(ones > k || s[i] == '0'){
                if(s[i] == '1'){
                    ones--;
                }
                i++;
            }

            if(ones == k){

                int len = j-i+1;
                string temp = s.substr(i, len);
                if(result == "" || len < result.size() || (len == result.size() && temp < result)){
         
                    result = temp;
                }
            }
            j++;
            
        }

        return result;
    }
};