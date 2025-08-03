
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        int n = intervals.size();
        vector<vector<int>>ans;

        sort(intervals.begin() , intervals.end());

        for(int i=0;i<n;i++) {
         
         if(ans.empty())
            {

                ans.push_back(intervals[i]);
            }
            else {
                vector<int>&v = ans.back();
                // y -> end value of previous interval
                int y = v[1]; 

                // overlap
                // [i][o] ->start value of current interval
                if(intervals[i][0] <= y) {
                    v[1] = max(y , intervals[i][1]);

                }
                // not overlapping
                else  {
                    ans.push_back(intervals[i]);


                
                }

            }
        }
        return ans;

    }
};