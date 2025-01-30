class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int left = 1;
        int right = *max_element(candies.begin(), candies.end()) + 1; // Binary search range
        while (left < right) {
            long long sum = 0;
            int mid = (left + right) / 2; // Midpoint
            for (auto i : candies) {
                sum += i / mid; //  total children satisfied with mid candies each
            }
            if (k > sum) { // If fewer children are satisfied
                right = mid; // Move left
            } else {
                left = mid + 1; // Move right
            }
        }
        return left - 1; // Result is left - 1
    }
};