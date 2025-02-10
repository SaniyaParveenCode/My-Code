class Solution {
public:
int i =0;
    string clearDigits(string s) {
    while(i<s.length())      {     
    if(isdigit(s[i])) {
            s.erase(i , 1);
            if(i-1 >= 0) {
            s.erase(i-1 ,1);
            i--;
            }
            }
            else {
                i++;
            }
        }
        return s;
    }
};