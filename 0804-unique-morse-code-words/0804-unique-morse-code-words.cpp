class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> table = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", 
                                "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", 
                                "..-", "...-", ".--", "-..-", "-.--", "--.."};
        unordered_set<string> uniqueTransformations;
        
        for (const auto& word : words) {  
            string str;
            for (char c : word) {  
                str += table[c - 'a'];  
            }
            uniqueTransformations.insert(str);  
        }
        
        return uniqueTransformations.size(); 
    }
};
