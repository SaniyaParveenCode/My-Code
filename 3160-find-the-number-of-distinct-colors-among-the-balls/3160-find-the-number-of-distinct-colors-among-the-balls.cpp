class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> color;
        unordered_map<int, int> colorFreq;
        vector<int> result(queries.size());

        for (int i = 0; i < queries.size(); i++) {
            int freq = colorFreq[queries[i][1]];
            colorFreq[queries[i][1]] = freq + 1;

            if (color.find(queries[i][0]) != color.end()) {
                int val = color[queries[i][0]];
                color[queries[i][0]] = queries[i][1];
                freq = colorFreq[val];
                colorFreq[val] = freq - 1;

                if (colorFreq[val] == 0) {
                    colorFreq.erase(val);
                }
            } else {
                color[queries[i][0]] = queries[i][1];
            }

            result[i] = colorFreq.size();
        }

        return result;
    }
};