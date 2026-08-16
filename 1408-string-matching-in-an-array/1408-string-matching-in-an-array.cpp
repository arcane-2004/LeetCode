class Solution {
    bool check(vector<string>& words, string s){
        for(int i=0; i<words.size(); i++){
            if(words[i].size() > s.size()){
                if(words[i].find(s) != string::npos){
                    return true;
                }

            }
        }

        return false;
    }
public:
    vector<string> stringMatching(vector<string>& words) {
        
        int n = words.size();
        vector<string> ans;

        for(int i=0; i<n; i++){
            if(check(words, words[i])){
                ans.push_back(words[i]);
            }
            
        }

        return ans;
    }

};