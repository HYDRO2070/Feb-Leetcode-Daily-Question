class Solution {
public:
    string clearDigits(string &s) {
        string ans = "";
        const int n = s.size();
        for(int i = 0;i < n;i++){
            if(s[i] >= 'a' && s[i] <= 'z') ans.push_back(s[i]);
            else ans.pop_back();
        }
        return ans;
    }
};


// using stack
// class Solution {
// public:
//     string clearDigits(string s) {
//         stack<char> st;
//         int n = s.size();
//         for(int i = 0;i < n;i++){
//             if(s[i] >= 'a' && s[i] <= 'z') st.push(s[i]);
//             else st.pop();
//         }
//         string ans = "";
//         while(!st.empty()){
//             ans = st.top() + ans;
//             st.pop();
//         }
//         return ans;
//     }
// };
