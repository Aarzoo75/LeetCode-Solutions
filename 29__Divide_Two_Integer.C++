class Solution {
public:
    int divide(long long dividend, long long divisor) {
        long long result;
        int ans;
        result = dividend / divisor;
        if(result < INT_MIN)
        {
            return INT_MIN;
        }
        else if(result > INT_MAX)
        {
            return INT_MAX;
        }
        else
        {
            ans = result;
            return ans;
        }
    }
};