class Solution {
    public void nextPermutation(int[] nums) {
        if(nums.length==1 || nums.length==0)
            return;
        
        int n = nums.length;
        int index = n-2; //last but one position
        
        //1)first find that index, which needs to be replaced -> nums[index]<nums[index+1]
        
        while(index>=0 && nums[index]>=nums[index+1]){
            index--;
        }
        
        //2)now find that swappedIndex, which is greater than index
        
        //edge case - index>=0; if index<=0 next permutation is not possible, just reverse the element and return
        if(index>=0){
            int swappedIndex = n-1;
            
            while(nums[index]>=nums[swappedIndex]){
                swappedIndex--;
            }
            
            int temp = nums[index];
            nums[index] = nums[swappedIndex];
            nums[swappedIndex] = temp;

        }
        
        //3) Reverse the elements from index+1 position, to get the lease next Permutation
        reverse(nums,index+1);
        
    }
    
    public void reverse(int[] nums,int start){
        int end = nums.length-1;
        while(start<=end){
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }
}