class Solution {

    string generate(string& s){
        int arr[26] = {0};

        for(char ch: s){
            arr[ch - 'a'] += 1;
        } 

        string temp = "";

        for(int i=0; i<26; i++){
            int freq = arr[i];

            if(freq > 0){
                temp += string(freq, i+'a');
            }
        }

        return temp;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> mp;

        for(string s: strs){
            
            string newStr = generate(s);

            mp[newStr].push_back(s);
        }

        vector<vector<string>> ans;
        for(auto i: mp){
            ans.push_back(i.second);
        }

        return ans;
    }
};