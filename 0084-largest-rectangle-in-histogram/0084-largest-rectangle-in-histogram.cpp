class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> s;
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        int maxarea = 0;

        // Calculate left boundaries
        for (int i = 0; i < n; i++) {
            while (!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            left[i] = s.empty() ? 0 : s.top() + 1;
            s.push(i);
        }

        while (!s.empty()) s.pop();

        // Calculate right boundaries
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            right[i] = s.empty() ? n - 1 : s.top() - 1;
            s.push(i);
        }

        // Calculate the maximum area
        for (int i = 0; i < n; i++) {
            maxarea = max(maxarea, (right[i] - left[i] + 1) * heights[i]);
        }

        return maxarea;
    }
};
