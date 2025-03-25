class Solution {
public:
    
    bool isPossible(vector<vector<int>>& rectangles, int k) {
        sort(rectangles.begin(), rectangles.end(), [k](const vector<int>& a, const vector<int>& b) {
            return a[k] < b[k]; 
        });

        int cuts = 0;  
        int mx = rectangles[0][k + 2];  

        for (int i = 1; i < rectangles.size(); i++) { 
            int b = rectangles[i][k];    
            int e = rectangles[i][k + 2]; 

            if (mx <= b) cuts++;
            
            mx = max(mx, e);
        }

        return cuts >= 2;
    }

    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        return isPossible(rectangles, 0) || isPossible(rectangles, 1);
    }
};