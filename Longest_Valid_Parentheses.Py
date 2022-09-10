class Solution:
    def longestValidParentheses(self, s: str) -> int:
        stack = []
        flags = [False] * len(s)
        
        # Set flags as True for complete parentheses
        i = 0
        for ch in s:            
            if ch == '(':
                stack.append(i)
            elif ch == ')':
                if stack:
                    flags[i] = True
                    flags[stack.pop()] = True
            i += 1  
                
        # Count the longest consecutive True
        #print(flags)
        cnt = 0
        maxCnt = 0
        for i in flags:
            if i:
                cnt += 1
            else:
                maxCnt = max(maxCnt, cnt)
                cnt = 0
        
        return max(maxCnt, cnt)
