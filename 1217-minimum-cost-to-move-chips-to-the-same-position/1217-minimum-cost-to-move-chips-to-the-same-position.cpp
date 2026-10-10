class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        


        long sum1 = 0;
        long sum2 = 0;

        for(int i=0; i<position.size(); i++){

            if(position[i] % 2 == 0){
                sum1 ++;
            }
            else{
                sum2 ++;
            }
        }

        return min(sum1, sum2);
    }
};