class Solution:
    def countAndSay(self, n: int) -> str:
        
        def transpose(string):
            count = 0
            
            res = ""
            
            char = string[0]
            
            for x in string:
                if char == x:
                    count += 1
                    
                    
                else:
                    res += str(count)
                    res += char
                    char = x
                    count = 1
                    
            res += str(count)
            res += char
            
            return res
            
            
                    
        def recurse(n):
            if n == 1:
                return "1"
            
            return transpose(recurse(n - 1))
                
            
        return recurse(n)