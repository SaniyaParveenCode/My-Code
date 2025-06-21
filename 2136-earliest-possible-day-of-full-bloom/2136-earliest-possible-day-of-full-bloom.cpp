class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        vector<pair<int, int>> ans(n);
        
        for (int i = 0; i < n; ++i) {
            ans[i] = {plantTime[i], growTime[i]};
        }

        sort(ans.begin(), ans.end(), [](pair<int, int>& a, pair<int, int>& b) {
            return b.second < a.second;
        });

        int mxtime = 0, tp = 0;
        for (int i = 0; i < n; ++i) {
            tp += ans[i].first;
            mxtime = max(mxtime, tp + ans[i].second);
        }

        return mxtime;
    }
};