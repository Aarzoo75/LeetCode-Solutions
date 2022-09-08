class Solution {
public:
    bool isValid(string s) {
        stack<char> brackets;
        for(int i=0;i<s.size();i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                brackets.push(s[i]);
            }
            else{
                if(!brackets.empty()){
                    char temp = brackets.top();
                    if((temp == '(' && s[i] == ')') || (temp == '{' && s[i] == '}') || (temp == '[' && s[i] == ']')){
                        brackets.pop();
                    }
                    else{
                        return false;
                    }    
                }
                else{
                    return false;
                }       
            }
        }
        if(!brackets.empty()){
            return false;
        }      
        return true;
    }
};