class Solution {
public:
    string modifyString(string s) {
        
        for(int i = 0;i<s.size();i++) 

            if(s[i] == '?') 
                for(int c = 'a'; c <='z';c++) {
                    if(i-1 >= 0 && s[i-1]==c ) continue;
                    if(i+1 < s.size() && s[i+1]==c ) continue;
                    s[i] = c;
                break;
        }
        return s;
    }
};