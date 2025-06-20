// 1-Reverse the entire array.
// 2-Reverse the first k elements.
// 3-Reverse the remaining elements.



class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
            k = k % n;
            reverse(nums.begin() , nums.end());
            reverse(nums.begin(), nums.begin() + k);
            reverse(nums.begin() +k , nums.end());
    }
};
