class ProductOfNumbers {
    private:
    vector<int> store;
public:
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        store.push_back(num);
    }
    
    int getProduct(int k) {
        int ans = 1;
        int n = store.size();
        for(int i = n-1;i >= n-k;i--) ans *= store[i];
        return ans;
    }
};



class ProductOfNumbers {
    private:
    vector<int> store;
    int size;
public:
    ProductOfNumbers() {
        store.push_back(1);
        this->size = 1;
    }
    
    void add(int num) {
        if(num == 0){
            store.clear();
            store.push_back(1);
            this->size = 1;
            return;
        }
        store.push_back(num*store[size-1]);
        this->size++;
    }
    
    int getProduct(int k) {
        if(this->size-1 < k) return 0;
        else return store[this->size-1] / store[this->size-1-k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
