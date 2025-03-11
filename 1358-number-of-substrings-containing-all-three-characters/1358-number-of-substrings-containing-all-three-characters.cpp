class Solution {
public:
    int numberOfSubstrings(string s) {
        int start = 0, count = 0;
        int freq[3] = {0}; 
        int end = 0; 

        while (end < s.size()) { 
            freq[s[end] - 'a']++; 
            while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {
                count += s.size() - end; 
                freq[s[start] - 'a']--;  
                start++;
            }

            end++; 
        }

        return count;
    }
};
