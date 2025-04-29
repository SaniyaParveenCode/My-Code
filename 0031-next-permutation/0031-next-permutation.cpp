class Solution {
public:
void nextPermutation(vector<int>& nums) {
    int n = nums.size(), i = n - 2, j;
    // Step 1: Find the pivot
    while (i >= 0 && nums[i] >= nums[i + 1]) 
        i--;
    if (i >= 0) {
        // Step 2: Find the successor
        j = n - 1;
        while (nums[j] <= nums[i]) 
            j--;
        // Step 3: Swap pivot and successor
      swap(nums[i], nums[j]);
    }
    // Step 4: Reverse the suffix
    reverse(nums.begin() + i + 1, nums.end());
}
};

// T.C = O(N);
// S.C = O(1);