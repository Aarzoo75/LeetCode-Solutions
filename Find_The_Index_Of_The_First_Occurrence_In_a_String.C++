/*
string substr (size_t pos, size_t len) const;
pos: Position of the first character to be copied.
len: Length of the sub-string.
size_t: It is an unsigned integral type.

returns: It returns a string object.
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        const int n = haystack.size();
        const int m = needle.size();
        
        // inavalid case
        if(m>n)
            return -1;
        
		// if both the strings are equal
        if(m==n && haystack==needle)
            return 0;
        
        for(int i=0;i<=n-m;i++)
        {
            string s = haystack.substr(i,m);
            if(s==needle)
                return i;
        }
        return -1;
    }
};
