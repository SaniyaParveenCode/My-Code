class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> allowedSet(allowed.begin() , allowed.end());
        int count = words.size();
        for(auto word : words) {
            for(char c: word) {
                if(allowedSet.find(c) == allowedSet.end()) {
                    count--;
                    break;
                }
            }
        }
        return count;  
    }
};