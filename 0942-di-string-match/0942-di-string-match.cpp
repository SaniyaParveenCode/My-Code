class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.size();
        vector<int>perm(n+1);
        int left = 0 , right = n;

        for(int i = 0;i<n;i++) {
            if(s[i] == 'I') {
                perm[i] = left++;
            }
            else {
                perm[i] = right--;
            }
        }
        perm[n] = left;
        return perm;
    }
};
