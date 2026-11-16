class Solution {
public:
    string digitSum(string s, int k) {
        while(s.length() > k){
            string str ="";
            for(int i=0;i<s.length();i += k){
                int sum=0;
                for(int j=i;j<min((int)s.length(),i+k);j++){
                    sum += s[j] -'0';
                }
                str += to_string(sum);
            }
            s=str;
        }
        return s;
    }
};