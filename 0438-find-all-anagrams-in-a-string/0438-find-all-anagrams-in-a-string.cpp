class Solution {
public:
//     vector<int> findAnagrams(string s, string p) {
//         int n = s.size();
//         vector<int>freq(n , 0);
    
//         for(int i=0;i<p.size();i++) {
//             char ch = p[i];
//             freq[ch-'a']++;            
//         }
//     }
// };


vector<int> findAnagrams(string s, string p) {
    vector<int> result;
    if (s.size() < p.size()) return result;

    vector<int> freq(26, 0); // To store frequency of characters in 'p'
    for (char c : p) freq[c - 'a']++; 

    int left = 0, right = 0, count = p.size(); // Sliding window pointers and count

    while (right < s.size()) {
        // Reduce count if character is in pattern
        if (freq[s[right] - 'a'] > 0) 
            count--;

        freq[s[right] - 'a']--; // Decrease frequency in window
        right++;

        // If window size matches pattern size, check result
        if (right - left == p.size()) {
            if (count == 0) result.push_back(left); // Found an anagram
            // Restore frequency and move left pointer
            if (freq[s[left] - 'a'] >= 0) count++;
            freq[s[left] - 'a']++;
            left++;
        }
    }
    return result;

}
};
