class Solution {
    public boolean isPalindrome(int x) {
        
        int sum=0;
        int y=x;
        
        while(y>0){
            int rem = y%10;
            sum = sum*10+rem;
            y = y/10;
        }
        return (sum==x);
    }
}
