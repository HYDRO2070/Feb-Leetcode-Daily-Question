class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long ans = 0;
        const int n = nums.size();
        unordered_map<int,int> m;

        for(int i =0;i <n;i++){
            int temp = nums[i] - i;
            ans += m[temp];
            m[temp]++;
        }
        return ((1ll * n*(n-1)) / 2) - ans;
    }
};
