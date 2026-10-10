class Solution {
public:
    int minRotations(string s) {
        int a=0;
        int sum =0;
        for(int i=0;i<s.length();i++){
            int b=s[i] - '0';
            int clock = abs(a-b);
            int anti = 10 - clock;

            int mini = min(clock,anti);
            sum+=mini;
            a=b;
        }
        return sum;
    }
};