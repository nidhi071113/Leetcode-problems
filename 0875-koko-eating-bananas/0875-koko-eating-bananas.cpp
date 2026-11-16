class Solution {
private:
    long long findHrs(vector<int> &arr,int h){
        long long total = 0;
        for(int i=0;i<arr.size();i++){
            total += (long long)(arr[i]+h-1)/h;
        }
        return total;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high=0;
        for(int pile:piles){
            high = max(high,(int)pile);
        }
        while(low<=high){
            int mid = low+(high-low)/2;
            long long total = findHrs(piles,mid);

            if(total <= h){
                high =mid-1;
            }
            else{
                low =mid+1;
            }
        }
        return low;
    }
};