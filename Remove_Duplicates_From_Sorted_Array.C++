class Solution {
    int help(vector<int>& help){
        vector<int> helpCopy; 
        int n = help.size();
        helpCopy.push_back(help[0]);
        
        // copy unique element original to helpCopy vector
        for(int i = 1; i< n; i++){
            if(helpCopy.back() != help[i]){
                
                int val = help[i];
                helpCopy.push_back(val);
            }
        }
        
        // then placed helpCopy element to original vector help and return helpCopy size 
        for(int i = 0; i< helpCopy.size(); i++)
            help[i] = helpCopy[i];
        
        return helpCopy.size();
    }
public:
    int removeDuplicates(vector<int>& nums) {
        return help(nums);
    }
};
