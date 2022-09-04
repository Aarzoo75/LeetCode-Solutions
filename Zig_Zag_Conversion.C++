class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        
        vector<string> vec(numRows, "");
		bool isPos = true;
        int idx = 0, realRows = numRows-1;
        
        for (int i = 0; i < s.length(); ++i) {
            vec[idx].push_back(s[i]);
            idx = isPos ? ++idx : --idx;
            if (numRows == 2) { isPos = !isPos; }
            else if (idx <= 0) { idx = 0; isPos = true; } 
            else if (idx > realRows) { idx = realRows-1; isPos = false; }
        }
        
        string res = "";
        
        for (int i = 0; i < vec.size(); ++i) {
            res += vec[i];
        }
        
        return res;
    }
};
