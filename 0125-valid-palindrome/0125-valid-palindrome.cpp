class Solution {

    bool check(char ch){
        if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')){
            return true;
        }

        return false;
    }

    char lower(char ch){
        if((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')){
            return ch;
        }
        char ans = ch - 'A' + 'a';
        return ans;
    }

public:
    bool isPalindrome(string s) {
        
        int n = s.length();
        int l = 0;
        int r = n-1;

        while(l < r){
            while(!check(s[l]) && l < r){
                l++;
            }
            while(!check(s[r]) && l < r){
                r--;
            }

            char ch1 = lower(s[l]);
            char ch2 = lower(s[r]);
   
            if(ch1 != ch2){
                return false;
            }
            l++;
            r--;


        }

        return true;
    }
};