class Solution {
public:
    bool areAlmostEqual(const string &s1, const string &s2) {
        const int n = s1.size();
        int c1 = -1,c2 = -1;
        for(int i = 0;i < n;i++){
            if(s1[i] != s2[i]){
                if(c1 == -1) c1 = i;
                else if(c2 == -1) c2 = i;
                else return false;
            }
        }
        if(c1 == -1 && c2 == -1) return true;
        if(c1 == -1 || c2 == -1 || s1[c1] != s2[c2] || s1[c2] != s2[c1]) return false;
        return true;
    }
};
