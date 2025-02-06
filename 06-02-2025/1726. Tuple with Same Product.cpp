class Solution {
    private:
    bool check(pair<int,int> &a,pair<int,int> &b){
        if(a.first == a.second || a.second == b.first || b.first == b.second) return false;
        return true;
    }
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,vector<pair<int,int>>> m;
        int ans = 0;
        int n = nums.size();
        for(int i = 0;i < n;i++){
            for(int j = i+1;j < n;j++){
                int temp = nums[i] * nums[j];
                m[temp].push_back({i,j});
            }
        }
        for(auto& arr : m){
            int size = arr.second.size();
            for(int i = 0;i < size;i++){
                for(int j = i+1;j < size;j++){
                    if(check(arr.second[i],arr.second[j])) ans += 8;
                }
            }
        }
        return ans;
    }
};
