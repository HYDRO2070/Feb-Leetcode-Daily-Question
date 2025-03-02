class Solution {
public:
    int mod = 1000000007;

    int numOfSubarrays(vector<int>& arr) {
        long long sum =
            0;
        int odd = 0;  
        int even = 0;
        long long ans =
            0;

        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];

            if (sum % 2 == 1) { 
                odd++;          
                ans += even + 1;
            } else {             
                even++;        
                ans += odd; 
            }
        }

        return ans % mod; 
    }
};
