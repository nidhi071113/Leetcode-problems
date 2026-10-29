class Solution {
public:
    int calculateScore(int a, int b) {
        int s1 = 0 , s2 = 0;

        int numA = a;
        while(numA > 0){
            numA = numA & (numA-1);
            s1++;
        }

        int numB = b;
        while(numB > 0){
            numB = numB & (numB-1);
            s2++;
        }

        if(s1 >= s2){
            return s1 * s2;
        }
        else{
            return s2/s1;
        }
    }
};