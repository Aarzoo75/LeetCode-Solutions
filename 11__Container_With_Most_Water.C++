class Solution {
public:
    int maxArea(vector<int>& height) {
        int l =0,r = height.size() - 1,maxHeight = min(height[r],height[l]);
        int area = (r-l) * maxHeight;
        while(l < r)
        {
            maxHeight = max(maxHeight,min(height[l],height[r]));
            area = max(area,(r-l) * min(height[l],height[r]));
    //we move the pointer with the smaller number so that we can maximise each height
            if(height[r] < height[l])
                r--;
            else 
                l++;
            
        }
        return area;
    }
};