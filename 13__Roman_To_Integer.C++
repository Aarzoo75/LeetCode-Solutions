class Solution {
public:
    int romanToInt(string s) {
        int sum =0;
        map<char, int> m;
            m['I']=1;
            m['V'] = 5;
            m['X'] = 10;
            m['L'] = 50;
            m['C'] = 100;
            m['D'] = 500;
            m['M'] = 1000;
            
      
        
        int ans =0,n=s.length();
        if(n==1)
            return m[s[0]];
        for(int i=0;i<s.length()-1;i++)
        {
            if(m[s[i]]>= m[s[i+1]])
                ans+= m[s[i]];
            else{
                ans+=(m[s[i+1]]-m[s[i]]);
                i++;
            }
                
        }
        if(n>=2&&m[s[n-2]]>=m[s[n-1]])
            ans+=m[s[n-1]];
        return ans;
        
    }
};