class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end()); // O(n)

        int longest = 0;

        for (int num : s) {
            // Check if it's the start of a sequence
            if (s.find(num - 1) == s.end()) {
                int current = num;
                int length = 1;

                while (s.find(current + 1) != s.end()) {
                    current++;
                    length++;
                }

                longest = max(longest, length);
            }
        }

        return longest;
    }
};
