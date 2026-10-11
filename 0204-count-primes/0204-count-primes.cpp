// class Solution {
// public:
//     int countPrimes(int n) {
//         if(n <=2) return 0;
        
//         int count = 0;
//         for(int i=2;i<n;i++){
//             bool check = true;

//             for(int j=2;j*j<=i;j++){
//                 if(i%j == 0){
//                     check = false;
//                     break;
//                 }
//             }

//             if(check){
//                 count++;
//             }
//         }
//         return count;
//     }
// };



class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        
        vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false; 
        
        for (int p = 2; p * p < n; p++) {
            if (isPrime[p]) 
            {
                for (int i = p * p; i < n; i += p) {
                    isPrime[i] = false;
                }
            }
        }
        
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) count++;
        }
        
        return count;
    }
};