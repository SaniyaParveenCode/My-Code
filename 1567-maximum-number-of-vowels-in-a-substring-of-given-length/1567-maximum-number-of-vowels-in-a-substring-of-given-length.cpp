class Solution {
public:
    int maxVowels(string s, int k) {
        int count = 0, ans = 0;
        int n = s.size();

        // Count vowels in the first window
        for (int i = 0; i < k; i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                count++;
            }
        }
        ans = count; // Initialize answer with first window result

        // Sliding window
        for (int i = k; i < n; i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                count++;
            }
            if (s[i - k] == 'a' || s[i - k] == 'e' || s[i - k] == 'i' || s[i - k] == 'o' || s[i - k] == 'u') {
                count--;
            }
            ans = max(ans, count);
        }    
        return ans;
    }
};
