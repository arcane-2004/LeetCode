class Solution {
public:
    int minOperations(vector<string>& logs) {
        
        stack<string> s;
        for(string log: logs){
            if(log != "./" && log != "../"){
                s.push(log);
            }

            else if(log == "../"){
                if(!s.empty()){
                    s.pop();
                }
            }
        }

        return s.size();
    }
};