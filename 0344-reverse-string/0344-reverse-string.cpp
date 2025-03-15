class Solution {
public:
void reverseString(vector<char>& s) {
    stack<char>str;
    int n = s.size();

    for(int i = 0;i<n;i++) {
        str.push(s[i]);
    }
    for(int i = 0;i<n;i++) {
        s[i] = str.top();
        str.pop();
            }
    }
};

