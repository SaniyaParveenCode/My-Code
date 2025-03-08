class Solution {
public:
    int findMaxK(vector<int>& nums) {
       unordered_set<int>st;

       int result = -1;

       for(int num:nums) {
        if(st.count(-num)) {
            result = max(result , abs(num));
        }
        st.insert(num);
       }
       return result;
    }
};