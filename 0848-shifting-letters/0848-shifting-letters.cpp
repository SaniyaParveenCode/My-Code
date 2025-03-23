class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        long long totalShift = 0; // To store cumulative shifts
        for (int i = shifts.size() - 1; i >= 0; i--) {
            totalShift = (totalShift + shifts[i]) % 26; // Calculate total shift modulo 26
            s[i] = 'a' + (s[i] - 'a' + totalShift) % 26; // Update character with shift
        }
        return s;
    }
};
