class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        
        string s = "";
        int l1 = word1.length();
        int l2 = word2.length();
        int i = 0, j = 0;

        while(i < l1  && j < l2){
            s = s + word1[i] + word2[j];
            i++;
            j++;
        }

        if(i < l1){
            s += word1.substr(i, l1-i);
        }
        else if(j < l2){
            s += word2.substr(j, l2-j);
        }

        return s;

    }
};