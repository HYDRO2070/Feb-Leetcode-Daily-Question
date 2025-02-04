class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int ans = 0,sum = 0;
        bool m = false;
        for(int i = 0;i < n;i++){
            ans = max(ans,nums[i]);
            if(i+1 < n){
                if(nums[i] < nums[i+1]){
                    sum += nums[i];
                    m = true;
                }
                else{
                    if(m) sum += nums[i];
                    ans = max(ans,sum);
                    sum = 0;
                }
            }
            else break;
        }
        ans = max(ans,sum+nums[n-1]);
        return ans;
    }
};
