class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>>  mh(nums.begin(), nums.end());
        int ans = 0;
        
        while (mh.top() < k) {
            ans++;
            
            long long n1 = mh.top();
            mh.pop();
            long long n2 = mh.top();
            mh.pop();
            
            mh.push(2 * n1 + n2);
        }
        
        return ans;
    }
};
