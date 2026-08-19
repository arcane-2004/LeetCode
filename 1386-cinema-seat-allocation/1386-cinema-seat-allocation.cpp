class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, unordered_set<int>> mp;
        int rows = reservedSeats.size();

        for(int i=0; i<rows; i++){
            int row = reservedSeats[i][0];
            int seat = reservedSeats[i][1];

            mp[row].insert(seat);
        }

        int ans = (n-mp.size()) * 2;

        for(auto& [row, booked]: mp){

            auto isAvailable = [&](int seat){
                return booked.find(seat) == booked.end();
            };

            bool groupA = isAvailable(2) && isAvailable(3) && isAvailable(4) && isAvailable(5);
            bool groupB = isAvailable(4) && isAvailable(5) && isAvailable(6) && isAvailable(7);
            bool groupC = isAvailable(6) && isAvailable(7) && isAvailable(8) && isAvailable(9);

            if(groupA && groupC){
                ans += 2;
            }
            else if(groupA || groupB || groupC){
                ans += 1;
            }


        }

        return ans;
    }
};