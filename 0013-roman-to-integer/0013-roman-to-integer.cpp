// 1-> Mapping Roman to Integer:
// Each Roman character has a specific value:

// 2-> Subtraction Rule:

// If the current Roman character (s[i]) is smaller than the next one (s[i+1]), subtract its value.

// Otherwise, add its value.


class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        unordered_map<char, int> mp{
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, 
            {'C', 100}, {'D', 500}, {'M', 1000}};

        for (int i = 0; i < s.size(); i++) {
            if (i < s.size() - 1 && mp[s[i]] < mp[s[i + 1]]) {
                ans = ans - mp[s[i]];
            } else {
                ans = ans + mp[s[i]];
            }
        }
        return ans;
    }
};
