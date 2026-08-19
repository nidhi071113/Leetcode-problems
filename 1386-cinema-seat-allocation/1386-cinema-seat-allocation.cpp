class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        ranges::sort(reservedSeats);
        int families = 2 * n;
        int m = reservedSeats.size();
        for (int i = 0; i < m;) {
            families -= 2;
            int row = reservedSeats[i][0];
            array<bool, 11> reserved{};
            while (i < m && reservedSeats[i][0] == row) {
                reserved[reservedSeats[i][1]] = true;
                i++;
            }
            auto& rs = reserved;
            if (!rs[2] && !rs[3] && !rs[4] && !rs[5]) {
                families++;
            } else if (!rs[4] && !rs[5] && !rs[6] && !rs[7] && (rs[8] || rs[9])) {
                families++;
            }
            if (!rs[6] && !rs[7] && !rs[8] && !rs[9]) {
                families++;
            }
        }
        return families;
    }
};