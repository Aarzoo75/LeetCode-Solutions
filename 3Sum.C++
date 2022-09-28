class Solution {
public:
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        
        for(int i = 0; i < nums.size(); i++) {
            if (i && nums[i] == nums[i - 1]) continue;
            int target = 0 - nums[i];
            for(int j = i + 1, k = nums.size() - 1; j < k; j++) {
                if(j > i + 1 && nums[j] == nums[j - 1]) continue;
                while(j < k - 1 && nums[j] + nums[k - 1] >= target) k--;
                if(nums[j] + nums[k] == target) {
                    res.push_back({nums[i], nums[j], nums[k]}) ;
                }
            }
        }
        return res;
    }
};
