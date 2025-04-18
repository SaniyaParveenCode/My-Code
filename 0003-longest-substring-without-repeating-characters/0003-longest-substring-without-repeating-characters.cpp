class Solution {
public:
    int lengthOfLongestSubstring(string S) {
    int max = 0;
    int start = 0;
    int end = 0;
    set<char>st;
    while(start < S.size()) {
        auto it = st.find(S[start]);
        if(it == st.end()) {
            if(start - end +1 > max) 
            max = start - end +1;
            st.insert(S[start]);
            start++;
        }
        else {
            st.erase(S[end]);
            end++;
        }
    }
    return max;
    }
};