class Solution {
public:
    
    void go(int idx,map<int,string> &kp,string &temp,string &num,vector<string> &ans){
        
               
        if(idx==num.size()){
            //cout<<temp<<" ";
            ans.push_back(temp);
            return;
        }
        
           
        for(auto j:kp[num[idx]-'0']){
                
                
            temp.push_back(j);
            go(idx+1,kp,temp,num,ans);
            temp.pop_back();

            
        }
        
    }
    
    vector<string> letterCombinations(string digits) {
     
        vector<string> ans;
        if(digits.size()==0) return {};
        map<int,string> keypad{
            
            {2,"abc"},
            {3,"def"},
            {4,"ghi"},
            {5,"jkl"},
            {6,"mno"},
            {7,"pqrs"},
            {8,"tuv"},
            {9,"wxyz"}       
            
        };
        
        
        string temp;
        go(0,keypad,temp,digits,ans);
        
        return ans;
    }
};
