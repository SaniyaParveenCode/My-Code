class Solution {
public:
    string reversePrefix(string word, char &ch) {
       int  n = word.size();
       int index = word.find(ch);
       if(index != string::npos) {
        // string::npos is a special constant in C++ that represents a value which indicates "not found" in string operations
        reverse(word.begin()  , word.begin() +index+1);
        // word.begin() +index+1 -> Points to the character just after the index of the first occurrence of ch
       }
       return word;
    }
};