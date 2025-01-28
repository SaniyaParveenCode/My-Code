#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib> // for abs

class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 3) return nums[0] + nums[1] + nums[2];

        // Sort the array for two-pointer technique
        sort(nums.begin(), nums.end());

        // Initialize Sum with the sum of the first three elements
        int Sum = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n - 2; i++) {
            int j = i + 1; // Second pointer
            int k = n - 1; // Third pointer

            while (j < k) {
                int currSum = nums[i] + nums[j] + nums[k];
                int currDiff = abs(currSum - target); // Current difference
                int diff = abs(Sum - target);        // Difference of closest sum

                // If we find the exact target, return it immediately
                if (currSum == target) {
                    return currSum;
                }

                // Update closest sum if the current difference is smaller
                if (currDiff < diff) {
                    Sum = currSum;
                }

                // Adjust pointers based on comparison with the target
                if (currSum < target) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        return Sum;
    }
};

int main() {
    // Create an instance of the Solution class
    Solution sol;

    // Test case: nums = [-1, 2, 1, -4], target = 1
    std::vector<int> nums = {-1, 2, 1, -4};
    int target = 1;

    // Call the function and print the result
    int result = sol.threeSumClosest(nums, target);
    std::cout << "The closest sum is: " << result << std::endl;

    return 0;
}
