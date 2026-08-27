class Solution {

    string result = "";

    bool solve(string& curr, string target, vector<int>& freq, int i, bool greater){
        if(i == target.length()){
            if(greater){
                result = curr;
                return true;
            } 

            return false;
        }
        
        for(char ch = 'a'; ch<='z'; ch++){
            if(!freq[ch - 'a']) continue;

            if(!greater && ch < target[i]) continue;

            curr.push_back(ch);
            freq[ch-'a']--;

            bool isGreater = greater || ch > target[i];
            if(solve(curr, target, freq, i+1, isGreater)) return true;

            curr.pop_back();
            freq[ch - 'a']++;
        }

        return false;
    }
public:
    string lexGreaterPermutation(string s, string target) {
        
        vector<int> freq(26, 0);
        for(char c: s){
    
            freq[c - 'a'] ++;
        }

        string curr = "";
        bool greater = false;

        solve(curr, target, freq, 0, greater);

        return result;
    }
};