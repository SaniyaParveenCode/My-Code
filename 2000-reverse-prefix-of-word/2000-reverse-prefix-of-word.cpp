// class Solution {
// public:
//     string reversePrefix(string word, char &ch) {
//        int  n = word.size();
//        int index = word.find(ch);
//        if(index != string::npos) {
//         reverse(word.begin()  , word.begin() +index+1);
//        }
//        return word;
//     }
// };

class Solution {
public:
    string reversePrefix(string word, char &ch) {
        int index = -1;

        for(int i=0;i<word.size();i++) {
            if(word[i]==ch) {
                index = i;
                break;

            }
        }
        if(index== -1)
        return word;
        for (int i = 0, j = index; i <= j; i++, j--) {
            swap(word[i] , word[j]);
        }
        return word;
    }
};
