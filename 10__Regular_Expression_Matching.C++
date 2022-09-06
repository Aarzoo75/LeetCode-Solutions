class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        s = ' ' + s, p = ' ' + p;
        vector<vector<bool>> f(n+1, vector<bool>(m+1));
        
        f[0][0] = true;
        
        for (int i = 0; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (j+1 <= m && p[j+1] == '*') continue; 
                if (p[j] != '*' && i)
                    f[i][j] = f[i-1][j-1] && (p[j] == '.' || p[j] == s[i]);
                    // if f[i-1][j-1] is true, ie current is legit
                    // and current RegEx can match the character in s
                else if (p[j] == '*')
                    f[i][j] = f[i][j-2] || (i && f[i-1][j] && (s[i] == p[j-1] || p[j-1] == '.'));
                    // p[j] current is *, p[j-1] is the matching character
                    // p[j-2] means ignore the matching (* can mean zero)
                    // if (s[i] match p[j-2]) then it is legit
                
                    //f[i][j] = f[i][j-2]   || f[i-1][j-2] && s[i] == p[j-1]   || f[i-2][j-2] && s[i-1] == p[j-2] && s[i-2] == p[j-3] ...
                    //           * == 0                 * == 1                           * == 2
                
                    // (f[i-1][j] && (s[i] == p[j-1] || p[j-1] == '.') 
                    // mean f[i-1][j]
                  //f[i-1][j] = f[i-1][j-2] || f[i-2][j-2] && s[i] == p[j-1]
            }
        }
        
        return f[n][m];
        
        
    }
};
