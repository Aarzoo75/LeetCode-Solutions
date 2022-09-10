class Solution {
public:
int removeElement(vector < int > & nums, int val) {

  int counter = 0;       // finding number of occurence of val
  for (int i = 0; i < nums.size(); i++) {      
    if (nums[i] == val)
      counter++;
  }

  for (int i = 0; i < counter; i++) {                    //      swapping val to last position of array

    for (int j = 0; j < nums.size(); j++) {

      if (nums[j] == val && j < nums.size() - 1) {                

        nums[j] = nums[j] + nums[j + 1];
        nums[j + 1] = nums[j] - nums[j + 1];
        nums[j] = nums[j] - nums[j + 1];

      }

    }
  }

  return (nums.size() - counter);

}
};
