class NumberContainers {
private:
    unordered_map<int, int> in;
    unordered_map<int, set<int>> num; 

public:
    NumberContainers() {}

    void change(int index, int number) {
        if (in.find(index) != in.end()) {
            int temp = in[index];
            if (temp == number) return;
            
            num[temp].erase(index);
            if (num[temp].empty()) num.erase(temp);
        }
        
        in[index] = number;
        num[number].insert(index);
    }

    int find(int number) {
        if (num.find(number) != num.end()) {
            return *num[number].begin();
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
