class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int cnt1 =0 , cnt2=0;

        for(int bill : bills){
            if(bill == 5) cnt1++;
            else if(bill == 10){
                if(cnt1){
                    cnt1--;
                    cnt2++;
                }
                else return false;
            }
            else{
                if(cnt1 && cnt2){
                    cnt1--;
                    cnt2--;
                }
                else if(cnt1 >=3) cnt1 -= 3;
                else return false;
            }
        }
        return true;
    }
};