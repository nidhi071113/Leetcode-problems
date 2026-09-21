class Solution {
public:
    string intToRoman(int num) {
        // Pairs of values and their corresponding Roman numeral representations
        const vector<pair<int, string>> valueSymbols = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"},  {90, "XC"},  {50, "L"},  {40, "XL"},
            {10, "X"},   {9, "IX"},   {5, "V"},   {4, "IV"},
            {1, "I"}
        };

        string ans = "";

        // Greedy matching: subtract the largest possible value
        for (const auto& [value, symbol] : valueSymbols) {
            while (num >= value) {
                ans += symbol;
                num -= value;
            }
        }

        return ans;
    }
};