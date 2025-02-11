class Solution {
public:
    string removeOccurrences(string s, string p) {
        bool flag = true;
        while(flag){
            string temp = "";
            flag = false;
            const int n = s.size();
            int i = 0;
            while(i < n){
                if(s[i] == p[0]){
                    const int m = p.size();
                    int j = 0;
                    int k = i;
                    while(k < n && j < m && s[k] == p[j]){
                        k++;
                        j++;
                    }
                    if(k - i == m){
                        i = k;
                        flag = true;
                    }
                    else{
                        temp.push_back(s[i++]);

                    }
                }
                else{
                    temp.push_back(s[i++]);
                }
                if(flag){
                    while(i < n) temp.push_back(s[i++]);
                    break;
                }
            }
            s = temp;
        }
        return s;
    }
};
