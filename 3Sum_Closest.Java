class Solution {
    public int threeSumClosest(int[] nums, int target) {
        int n = nums.length;
        int result = 0;
        int gap = Integer.MAX_VALUE;
        Arrays.sort(nums);
        for(int i = 0; i < n; i++){
            if(i == 0 || nums[i-1] != nums[i]){ //Avoid duplicate
                int low = i+1;
                int high = n-1;
                while(low < high){
                    int sum = nums[i] + nums[low] + nums[high];
                    int temp = Math.abs(sum - target); // The gap between our current sum and the target
                    if(sum < target){
                        if(temp < gap){
                            result = sum;
                            gap = temp;
                        }
                        low++; // Increase the left if our sum is smaller than target
                    }else if(sum > target){
                        if(temp < gap){
                            result = sum;
                            gap = temp;
                        }
                        high--; // Decrease the right if our sum is larger than target
                    }else{
                        result = sum;
                        return result; //Already equal
                    }
                }
            }
        }
        return result;
    }
}
