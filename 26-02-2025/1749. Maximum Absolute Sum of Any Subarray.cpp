class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxs = INT_MIN, mins = INT_MAX;
        int cur = 0, curr = 0;
        for (int num : nums) {
            cur += num;
            curr += num;
            maxs = max(cur, maxs);
            mins = min(curr, mins);
            if (cur < 0)
                cur = 0;
            if (curr > 0)
                curr = 0;
        }
        return max(abs(mins), maxs);
    }
};
