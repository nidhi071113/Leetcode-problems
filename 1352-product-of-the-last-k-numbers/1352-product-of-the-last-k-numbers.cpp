class ProductOfNumbers {
private:
    vector<long long> prefix;

public:
    ProductOfNumbers() {
        prefix = {1};
    }
    
    void add(int num) {
        if (num == 0) {
            prefix = {1};
        } else {
            prefix.push_back(prefix.back() * num);
        }
    }
    
    int getProduct(int k) {
        int n = (int)prefix.size() - 1;
        if (k > n) {
            return 0;
        }
        return (int)(prefix[n] / prefix[n - k]);
    }
};