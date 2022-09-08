class Solution {
    void solve(int n,int &openp,int &closep,vector<string> &output,string &ans){
        // if(openp > n || closep > n || closep > openp)return;
        
        if(openp == n && closep == n){
            output.push_back(ans);
            return;
        }
        
        if(openp < n){
            openp+=1;
            ans.push_back('(');
            solve(n,openp,closep,output,ans);
            openp-=1;
            ans.pop_back();
        }
        
        if(closep < openp){
            closep+=1;
            ans.push_back(')');
            solve(n,openp,closep,output,ans);
            closep-=1;
            ans.pop_back();
        }
        
        
    }
public:
    vector<string> generateParenthesis(int n) {
        int openp = 0;
        int closep = 0;
        vector<string> output;
        string ans = "";
        solve(n,openp,closep,output,ans);
        return output;
    }
};
