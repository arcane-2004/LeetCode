class Solution {
public:
    int calPoints(vector<string>& operations) {
        
        stack<string> board;

        for(string op: operations){
            if(op == "+"){
                string prv1 = board.top();
                board.pop();
                string prv2 = board.top();
                board.push(prv1);
                int sum = stoi(prv1) + stoi(prv2);
                board.push(to_string(sum));
            }

            else if(op == "D"){
                string prv = board.top();
                int dub = 2 * stoi(prv);
                board.push(to_string(dub));
            }

            else if(op == "C"){
                board.pop();
            }

            else{
                board.push(op);
            }
        }

        int ans = 0;
        while(!board.empty()){
            int n = stoi(board.top());
            board.pop();

            ans += n;
        }

        return ans;
    }

    
};