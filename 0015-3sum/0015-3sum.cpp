// class Solution {
// public:
// vector<vector<int>>threeSum(vector<int>&nums) {
//     sort(nums.begin(),nums.end());
//     vector<vector<int>>output;
//     for(int i=0;i<nums.size();i++) {
//         int first = nums[i];
//         int first = 
//     }
// }      
//     }
// };


class Solution {
public:
    // Helper function to find pairs with a given target sum
    void find2sum(vector<int>& nums, int i, int j, int target, vector<vector<int>>& ans) {
        while (i < j) {
            int sum = nums[i] + nums[j];

            if (sum > target) {
                j--; // Decrease the sum by moving the right pointer left
            } else if (sum < target) {
                i++; // Increase the sum by moving the left pointer right
            } else {
                ans.push_back({-target, nums[i], nums[j]}); // Found a valid triplet
                
                // Skip duplicates
                while (i < j && nums[i] == nums[i + 1]) i++;
                while (i < j && nums[j] == nums[j - 1]) j--;
                
                i++;
                j--;
            }
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;

        int n = nums.size();
        if (n < 3) return ans; // Not enough elements for a triplet

        sort(nums.begin(), nums.end()); // Sort the array

        for (int i = 0; i < n; i++) {
            // Skip duplicates for the current element
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int target = -nums[i]; // Target sum for the two-pointer search
            find2sum(nums, i + 1, n - 1, target, ans);
        }

        return ans;
    }
};